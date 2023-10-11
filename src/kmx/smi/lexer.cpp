// SMI Parser
// Copyright (c) 2023 KMX Systems. All rights reserved.
#include "kmx/smi/lexer.hpp"
#ifndef PCH
    #include <array>
    #include <iomanip>
    #include <iostream>
    #include <tuple>
    #include <unordered_map>
    #include <utility>
#endif

namespace kmx::smi
{
    namespace token
    {
        std::ostream& operator<<(std::ostream& out, const data& item)
        {
            using namespace std;
            cout << setw(5) << item.line_no() << ':' << setw(3) << item.column_no() << ' ' << text_of(item.id());
            if (item.value())
                cout << '\t' << *item.value();
            return out;
        }
    }

    static std::optional<token::id> find(const text_view_t& text)
    {
        using id = token::id;
        using map_t = const std::unordered_map<text_view_t, const id>;
        static const map_t map {{"ABSENT", id::absent},
                                {"ACCESS", id::access},
                                {"AGENT-CAPABILITIES", id::agent_capabilities},
                                {"ANY", id::any},
                                {"APPLICATION", id::application},
                                {"AUGMENTS", id::augments},
                                {"BEGIN", id::begin},
                                {"BIT", id::bit},
                                {"BITS", id::bits},
                                {"BOOLEAN", id::boolean},
                                {"BY", id::by},
                                {"CHOICE", id::choice},
                                {"COMPONENT", id::component},
                                {"COMPONENTS", id::components},
                                {"CONTACT-INFO", id::contact_info},
                                {"CREATION-REQUIRES", id::creation_requires},
                                {"DEFAULT", id::default_},
                                {"DEFINED", id::defined},
                                {"DEFINITIONS", id::definitions},
                                {"DEFVAL", id::defval},
                                {"DESCRIPTION", id::description},
                                {"DISPLAY-HINT", id::display_hint},
                                {"END", id::end},
                                {"ENTERPRISE", id::enterprise},
                                {"ENUMERATED", id::enumerated},
                                {"EXPLICIT", id::explicit_},
                                {"EXPORTS", id::exports},
                                {"FALSE", id::false_},
                                {"FROM", id::from},
                                {"GROUP", id::group},
                                {"IDENTIFIER", id::identifier},
                                {"IMPLICIT", id::implicit},
                                {"IMPLIED", id::implied},
                                {"IMPORTS", id::imports},
                                {"INCLUDES", id::includes},
                                {"INDEX", id::index},
                                {"INTEGER", id::integer},
                                {"LAST-UPDATED", id::last_updated},
                                {"MACRO", id::macro},
                                {"MANDATORY-GROUPS", id::mandatory_groups},
                                {"MAX", id::max_access},
                                {"MAX-ACCESS", id::max},
                                {"MIN", id::min_access},
                                {"MIN-ACCESS", id::min},
                                {"MINUS-INFINITY", id::minus_infinity},
                                {"MODULE", id::module_compliance},
                                {"MODULE-COMPLIANCE", id::module_identity},
                                {"MODULE-IDENTITY", id::module},
                                {"NOTIFICATION-GROUP", id::notification_group},
                                {"NOTIFICATIONS", id::notifications},
                                {"NOTIFICATION-TYPE", id::notification_type},
                                {"NULL", id::null},
                                {"OBJECT", id::object_group},
                                {"OBJECT-GROUP", id::object_identity},
                                {"OBJECT-IDENTITY", id::object},
                                {"OBJECTS", id::objects},
                                {"OBJECT-TYPE", id::object_type},
                                {"OCTET", id::octet},
                                {"OF", id::of},
                                {"OPTIONAL", id::optional},
                                {"ORGANIZATION", id::organization},
                                {"PLUS-INFINITY", id::plus_infinity},
                                {"PRESENT", id::present},
                                {"PRIVATE", id::private_},
                                {"PRODUCT-RELEASE", id::product_release},
                                {"REAL", id::real},
                                {"REFERENCE", id::reference},
                                {"REVISION", id::revision},
                                {"SEQUENCE", id::sequence},
                                {"SET", id::set},
                                {"SIZE", id::size},
                                {"STATUS", id::status},
                                {"STRING", id::string},
                                {"SUPPORTS", id::supports},
                                {"SYNTAX", id::syntax},
                                {"TAGS", id::tags},
                                {"TEXTUAL-CONVENTION", id::textual_convention},
                                {"TRAP-TYPE", id::trap_type},
                                {"TRUE", id::true_},
                                {"UNITS", id::units},
                                {"UNIVERSAL", id::universal},
                                {"VARIABLES", id::variables},
                                {"VARIATION", id::variation},
                                {"WITH", id::with},
                                {"WRITE-SYNTAX", id::write_syntax}};
        const auto pos = map.find(text);
        if (pos != map.end())
            return pos->second;
        return {};
    }

    constexpr auto nl = '\n';
    constexpr auto tab = '\t';

    static constexpr bool is_identifier(const char c) noexcept
    {
        return std::isalnum(c) || (c == '-') || (c == '_');
    }

    column_count_t file_location::column_no() const noexcept
    {
        return static_cast<column_count_t>(pointer_ - line_pointer_ + (tab_size_ - 1u) * tab_count_ + 1u);
    }

    lexer::lexer(const text_view_t& data, const tab_size_t tab_size) noexcept: token_(tab_size)
    {
        operator()(data);
    }

    void lexer::operator()(const text_view_t& data) noexcept
    {
        can_continue_ = !data.empty();
        if (can_continue_)
        {
            pointer_ = data.cbegin();
            line_pointer_ = data.cbegin();
            tab_count_ = 0u;
            end_ = data.cend();
            scan();
        }
    }

    void lexer::operator++() noexcept
    {
        if (can_continue_)
            scan();
    }

    void lexer::unexpected_char() noexcept
    {
        token_.set_id(token::id::unexpected_char);
        can_continue_ = {};
    }

    void lexer::incomplete_token() noexcept
    {
        token_.set_id(token::id::incomplete);
        can_continue_ = {};
    }

    void lexer::no_value() noexcept
    {
        token_.reset_value();
        can_continue_ = pointer_ != end_;
    }

    void lexer::set_token(const token::id token) noexcept
    {
        token_.set_id(token);
        no_value();
    }

    void lexer::set_token_and_increment(const token::id token) noexcept
    {
        ++pointer_;
        set_token(token);
    }

    void lexer::set_token(const token::id token, const text_view_t& text) noexcept
    {
        token_.set_id(token);
        token_.set_value(text);
        can_continue_ = pointer_ != end_;
    }

    void lexer::set_token_and_increment(const token::id token, const text_view_t& text) noexcept
    {
        token_ = *this;
        ++pointer_;
        set_token(token, text);
    }

    text_view_t lexer::create_text_view() noexcept
    {
        return {token_.pointer(), static_cast<std::size_t>(pointer_ - token_.pointer())};
    }

    void lexer::quoted_string() noexcept
    {
        ++pointer_;
        token_ = *this;
        for (; (pointer_ < end_) && (*pointer_ != '"'); ++pointer_)
        {
            switch (*pointer_)
            {
                case nl:
                {
                    ++line_no_;
                    line_pointer_ = pointer_ + 1;
                    tab_count_ = 0u;
                    break;
                }
                case tab:
                {
                    ++tab_count_;
                    break;
                }
                default:
                    break;
            }
        }

        if (pointer_ < end_)
        {
            token_.set_id(token::id::quoted_string);
            token_.set_value(create_text_view());
            ++pointer_;
        }

        can_continue_ = pointer_ != end_;
    }

    void lexer::check_number() noexcept
    {
        token_ = *this;
        for (; (pointer_ < end_) && std::isdigit(*pointer_); ++pointer_)
        {
        }

        const auto text = create_text_view();
        set_token(token::id::number_string, text);
    }

    enum class number_type
    {
        binary,
        hexadecimal,
    };

    void lexer::check_special_number() noexcept
    {
        token_ = *this;
        ++pointer_;
        if (pointer_ < end_)
        {
            number_type no_type {};
            bool break_loop {};
            while ((pointer_ < end_) && !break_loop)
            {
                switch (*pointer_)
                {
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                    case 'A':
                    case 'B':
                    case 'C':
                    case 'D':
                    case 'E':
                    case 'F':
                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'e':
                    case 'f':
                        if (no_type != number_type::hexadecimal)
                            no_type = number_type::hexadecimal;
                        [[fallthrough]];
                    case '0':
                    case '1':
                        ++pointer_;
                        break;
                    case '\'':
                        ++pointer_;
                        break_loop = true;
                        break;
                    default:
                        unexpected_char();
                        return;
                }
            }

            const auto text = create_text_view();
            using tuple_t = std::tuple<token::id, char, char>;
            static constexpr std::array<tuple_t, 2u> cases {
                tuple_t {token::id::binary_string, 'B', 'b'},
                tuple_t {token::id::hexadecimal_string, 'H', 'h'},
            };

            if (pointer_ < end_)
            {
                const auto& selected_item = cases[std::to_underlying(no_type)];
                if ((*pointer_ == std::get<1>(selected_item) || (*pointer_ == std::get<2>(selected_item))))
                {
                    set_token_and_increment(std::get<0>(selected_item), text);
                }
                else
                    unexpected_char();
            }
            else
                incomplete_token();
        }
        else
            incomplete_token();
    }

    void lexer::continue_identifier() noexcept
    {
        token_.line_pointer_ = line_pointer_;
        token_.line_no_ = line_no_;
        for (++pointer_; pointer_ < end_; ++pointer_)
        {
            if (!is_identifier(*pointer_))
            {
                break;
            }
        }

        set_token(token::id::identifier, create_text_view());
    }

    void lexer::identifier() noexcept
    {
        token_ = *this;
        continue_identifier();
    }

    void lexer::try_match_keyword() noexcept
    {
        const auto text = create_text_view();
        const auto possible_keyword = find(text);
        if (possible_keyword)
            set_token(*possible_keyword);
        else
            set_token(token::id::identifier, text);
    }

    void lexer::upper_case_string() noexcept
    {
        token_ = *this;
        for (++pointer_; (pointer_ < end_) && std::isupper(*pointer_); ++pointer_)
        {
        }

        if ((pointer_ < end_) && (std::islower(*pointer_) || std::isdigit(*pointer_) || (*pointer_ == '-') || (*pointer_ == '_')))
            continue_identifier();
        else
            try_match_keyword();
    }

    void lexer::new_line() noexcept
    {
        do
        {
            ++line_no_;
            ++pointer_;
        } while ((pointer_ < end_) && (*pointer_ == nl));

        line_pointer_ = pointer_;
        tab_count_ = 0;
        can_continue_ = pointer_ != end_;
    }

    void lexer::space() noexcept
    {
        for (++pointer_; pointer_ < end_; ++pointer_)
        {
            switch (*pointer_)
            {
                case ' ':
                    break;
                case tab:
                    ++tab_count_;
                    break;
                default:
                    can_continue_ = pointer_ != end_;
                    return;
            }
        }

        can_continue_ = {};
    }

    void lexer::comment() noexcept
    {
        token_ = *this;
        for (++pointer_; (pointer_ < end_) && (*pointer_ != nl); ++pointer_)
        {
        }

        can_continue_ = pointer_ != end_;
    }

    void lexer::dot() noexcept
    {
        token_ = *this;
        using token::id;
        const auto token =
            (pointer_ + 1 < end_) && (pointer_[1u] == '.') ?
                (pointer_ + 2 < end_) && (pointer_[2u] == '.') ? (pointer_ += 3, id::triple_dot) : (pointer_ += 2, id::double_dot) :
                id::dot;
        token_.set_id(token);
        no_value();
    }

    void lexer::definition_symbol() noexcept
    {
        token_ = *this;
        constexpr auto length = 3;
        if ((pointer_ + length < end_) && (pointer_[1] == ':') && (pointer_[2] == '='))
        {
            pointer_ += length;
            set_token(token::id::definition_symbol);
        }
        else
            unexpected_char();
    }

    void lexer::scan() noexcept
    {
        using token::id;
        while (can_continue_)
            switch (*pointer_)
            {
                case nl:
                    new_line();
                    break;
                case '\r':
                    ++pointer_;
                    break;
                case tab:
                    ++tab_count_;
                    [[fallthrough]];
                case ' ':
                    space();
                    break;
                case '-':
                    if (((pointer_ + 1) < end_) && (pointer_[1] == '-'))
                    {
                        comment();
                        break;
                    }

                    set_token_and_increment(id::minus);
                    return;
                case '.':
                    dot();
                    return;
                case ':':
                    definition_symbol();
                    return;
                case ';':
                    set_token_and_increment(id::semicolon);
                    return;
                case ',':
                    set_token_and_increment(id::comma);
                    return;
                case '{':
                    set_token_and_increment(id::bracket_left);
                    return;
                case '}':
                    set_token_and_increment(id::bracket_right);
                    return;
                case '(':
                    set_token_and_increment(id::paren_left);
                    return;
                case ')':
                    set_token_and_increment(id::paren_right);
                    return;
                case '<':
                    set_token_and_increment(id::less_than);
                    return;
                case '>':
                    set_token_and_increment(id::greater_than);
                    return;
                case '\'':
                    check_special_number();
                    return;
                case '"':
                    quoted_string();
                    return;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    check_number();
                    return;
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                case 'E':
                case 'F':
                case 'G':
                case 'I':
                case 'L':
                case 'M':
                case 'N':
                case 'O':
                case 'P':
                case 'R':
                case 'S':
                case 'T':
                case 'U':
                case 'V':
                case 'W':
                    upper_case_string();
                    return;
                case 'H':
                case 'J':
                case 'K':
                case 'Q':
                case 'X':
                case 'Y':
                case 'Z':
                case 'a':
                case 'b':
                case 'c':
                case 'd':
                case 'e':
                case 'f':
                case 'g':
                case 'h':
                case 'i':
                case 'j':
                case 'k':
                case 'l':
                case 'm':
                case 'n':
                case 'o':
                case 'p':
                case 'q':
                case 'r':
                case 's':
                case 't':
                case 'u':
                case 'v':
                case 'w':
                case 'x':
                case 'y':
                case 'z':
                    identifier();
                    return;
                default:
                    unexpected_char();
                    return;
            }
    }
}
