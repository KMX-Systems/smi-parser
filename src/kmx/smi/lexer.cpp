// SMI Parser
// Copyright (c) 2023 KMX Systems. All rights reserved.
#include "kmx/smi/lexer.hpp"
#ifndef PCH
    #include <array>
    #include <iostream>
    #include <tuple>
    #include <unordered_map>
    #include <utility>
#endif

namespace kmx::smi
{
    static std::optional<token_t> find(const text_view_t& text)
    {
        using map_t = const std::unordered_map<text_view_t, const token_t>;
        static const map_t map {{"ABSENT", token_t::absent},
                                {"ACCESS", token_t::access},
                                {"AGENT-CAPABILITIES", token_t::agent_capabilities},
                                {"ANY", token_t::any},
                                {"APPLICATION", token_t::application},
                                {"AUGMENTS", token_t::augments},
                                {"BEGIN", token_t::begin},
                                {"BIT", token_t::bit},
                                {"BITS", token_t::bits},
                                {"BOOLEAN", token_t::boolean},
                                {"BY", token_t::by},
                                {"CHOICE", token_t::choice},
                                {"COMPONENT", token_t::component},
                                {"COMPONENTS", token_t::components},
                                {"CONTACT-INFO", token_t::contact_info},
                                {"CREATION-REQUIRES", token_t::creation_requires},
                                {"DEFAULT", token_t::default_},
                                {"DEFINED", token_t::defined},
                                {"DEFINITIONS", token_t::definitions},
                                {"DEFVAL", token_t::defval},
                                {"DESCRIPTION", token_t::description},
                                {"DISPLAY-HINT", token_t::display_hint},
                                {"END", token_t::end},
                                {"ENTERPRISE", token_t::enterprise},
                                {"ENUMERATED", token_t::enumerated},
                                {"EXPLICIT", token_t::explicit_},
                                {"EXPORTS", token_t::exports},
                                {"FALSE", token_t::false_},
                                {"FROM", token_t::from},
                                {"GROUP", token_t::group},
                                {"IDENTIFIER", token_t::identifier},
                                {"IMPLICIT", token_t::implicit},
                                {"IMPLIED", token_t::implied},
                                {"IMPORTS", token_t::imports},
                                {"INCLUDES", token_t::includes},
                                {"INDEX", token_t::index},
                                {"INTEGER", token_t::integer},
                                {"LAST-UPDATED", token_t::last_updated},
                                {"MACRO", token_t::macro},
                                {"MANDATORY-GROUPS", token_t::mandatory_groups},
                                {"MAX", token_t::max_access},
                                {"MAX-ACCESS", token_t::max},
                                {"MIN", token_t::min_access},
                                {"MIN-ACCESS", token_t::min},
                                {"MINUS-INFINITY", token_t::minus_infinity},
                                {"MODULE", token_t::module_compliance},
                                {"MODULE-COMPLIANCE", token_t::module_identity},
                                {"MODULE-IDENTITY", token_t::module},
                                {"NOTIFICATION-GROUP", token_t::notification_group},
                                {"NOTIFICATIONS", token_t::notifications},
                                {"NOTIFICATION-TYPE", token_t::notification_type},
                                {"NULL", token_t::null},
                                {"OBJECT", token_t::object_group},
                                {"OBJECT-GROUP", token_t::object_identity},
                                {"OBJECT-IDENTITY", token_t::object},
                                {"OBJECTS", token_t::objects},
                                {"OBJECT-TYPE", token_t::object_type},
                                {"OCTET", token_t::octet},
                                {"OF", token_t::of},
                                {"OPTIONAL", token_t::optional},
                                {"ORGANIZATION", token_t::organization},
                                {"PLUS-INFINITY", token_t::plus_infinity},
                                {"PRESENT", token_t::present},
                                {"PRIVATE", token_t::private_},
                                {"PRODUCT-RELEASE", token_t::product_release},
                                {"REAL", token_t::real},
                                {"REFERENCE", token_t::reference},
                                {"REVISION", token_t::revision},
                                {"SEQUENCE", token_t::sequence},
                                {"SET", token_t::set},
                                {"SIZE", token_t::size},
                                {"STATUS", token_t::status},
                                {"STRING", token_t::string},
                                {"SUPPORTS", token_t::supports},
                                {"SYNTAX", token_t::syntax},
                                {"TAGS", token_t::tags},
                                {"TEXTUAL-CONVENTION", token_t::textual_convention},
                                {"TRAP-TYPE", token_t::trap_type},
                                {"TRUE", token_t::true_},
                                {"UNITS", token_t::units},
                                {"UNIVERSAL", token_t::universal},
                                {"VARIABLES", token_t::variables},
                                {"VARIATION", token_t::variation},
                                {"WITH", token_t::with},
                                {"WRITE-SYNTAX", token_t::write_syntax}};
        const auto pos = map.find(text);
        if (pos != map.end())
            return pos->second;
        return {};
    }

    const text_view_t& text_of(const token_t token)
    {
        using array_t = std::array<text_view_t, std::to_underlying(token_t::write_syntax) + 1u>;
        static constexpr array_t texts {
            // error
            "error:unexpected_char",
            "error:incomplete_token",

            // symbol
            "brace_left",
            "brace_right",
            "bracket_left",
            "bracket_right",
            "paren_left",
            "paren_right",
            "quote",
            "double_quote",
            "less_than",
            "greater_than",
            "comma",
            "dot",
            "minus",
            "pipe",
            "semicolon",
            "underscore",
            "double_dot",
            "triple_dot",
            "definition_symbol",

            // string
            "binary_string",
            "hexadecimal_string",
            "identifier_string",
            "number_string",
            "quoted_string",

            // keyword
            "absent",
            "access",
            "agent_capabilities",
            "any",
            "application",
            "augments",
            "begin",
            "bit",
            "bits",
            "boolean",
            "by",
            "choice",
            "component",
            "components",
            "contact_info",
            "creation_requires",
            "default_",
            "defined",
            "definitions",
            "defval",
            "description",
            "display_hint",
            "end",
            "enterprise",
            "enumerated",
            "explicit_",
            "exports",
            "false_",
            "from",
            "group",
            "identifier",
            "implicit",
            "implied",
            "imports",
            "includes",
            "index",
            "integer",
            "last_updated",
            "macro",
            "mandatory_groups",
            "max_access",
            "max",
            "min_access",
            "min",
            "minus_infinity",
            "module_compliance",
            "module_identity",
            "module",
            "notification_group",
            "notifications",
            "notification_type",
            "null",
            "object_group",
            "object_identity",
            "object",
            "objects",
            "object_type",
            "octet",
            "of",
            "optional",
            "organization",
            "plus_infinity",
            "present",
            "private_",
            "product_release",
            "real",
            "reference",
            "revision",
            "sequence",
            "set",
            "size",
            "status",
            "string",
            "supports",
            "syntax",
            "tags",
            "textual_convention",
            "trap_type",
            "true_",
            "units",
            "universal",
            "variables",
            "variation",
            "with",
            "write_syntax",
        };

        return texts[std::to_underlying(token)];
    }

    constexpr auto nl = '\n';
    constexpr auto tab = '\t';

    static bool is_identifier_char(const char c) noexcept
    {
        return std::isalnum(c) || (c == '-') || (c == '_');
    }

    std::size_t lexer::entity::column_no() const noexcept
    {
        return static_cast<std::size_t>(pointer_ - line_pointer_) + (tab_size_ - 1u) * tab_count_ + 1u;
    }

    lexer::lexer(const text_view_t& data, const tab_size_t tab_size) noexcept: entity_(tab_size)
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
        entity_.token_ = token_t::unexpected_char;
        can_continue_ = {};
    }

    void lexer::incomplete_token() noexcept
    {
        entity_.token_ = token_t::incomplete;
        can_continue_ = {};
    }

    void lexer::no_value() noexcept
    {
        entity_.token_value_.reset();
        can_continue_ = pointer_ != end_;
    }

    void lexer::set_token(const token_t token) noexcept
    {
        entity_.token_ = token;
        no_value();
    }

    void lexer::set_token_and_increment(const token_t token) noexcept
    {
        ++pointer_;
        set_token(token);
    }

    void lexer::set_token(const token_t token, const text_view_t& text) noexcept
    {
        entity_.token_ = token;
        entity_.token_value_ = text;
        can_continue_ = pointer_ != end_;
    }

    void lexer::set_token_and_increment(const token_t token, const text_view_t& text) noexcept
    {
        entity_ = *this;
        ++pointer_;
        set_token(token, text);
    }

    text_view_t lexer::create_text_view() noexcept
    {
        return {entity_.pointer_, static_cast<std::size_t>(pointer_ - entity_.pointer_)};
    }

    void lexer::quoted_string() noexcept
    {
        ++pointer_;
        entity_ = *this;
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
            entity_.token_ = token_t::quoted_string;
            entity_.token_value_ = create_text_view();
            ++pointer_;
        }

        can_continue_ = pointer_ != end_;
    }

    void lexer::check_number() noexcept
    {
        entity_ = *this;
        for (; (pointer_ < end_) && std::isdigit(*pointer_); ++pointer_)
        {
        }

        const auto text = create_text_view();
        set_token(token_t::number_string, text);
    }

    enum class number_type
    {
        binary,
        hexadecimal,
    };

    void lexer::check_special_number() noexcept
    {
        entity_ = *this;
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
            using tuple_t = std::tuple<token_t, char, char>;
            static constexpr std::array<tuple_t, 2u> cases {
                tuple_t {token_t::binary_string, 'B', 'b'},
                tuple_t {token_t::hexadecimal_string, 'H', 'h'},
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
        entity_.line_pointer_ = line_pointer_;
        entity_.line_no_ = line_no_;
        for (++pointer_; pointer_ < end_; ++pointer_)
        {
            if (!is_identifier_char(*pointer_))
            {
                break;
            }
        }

        set_token(token_t::identifier, create_text_view());
    }

    void lexer::identifier() noexcept
    {
        entity_ = *this;
        continue_identifier();
    }

    void lexer::try_match_keyword() noexcept
    {
        const auto text = create_text_view();
        const auto possible_keyword = find(text);
        if (possible_keyword)
            set_token(*possible_keyword);
        else
            set_token(token_t::identifier, text);
    }

    void lexer::upper_case_string() noexcept
    {
        entity_ = *this;
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
        entity_ = *this;
        for (++pointer_; (pointer_ < end_) && (*pointer_ != nl); ++pointer_)
        {
        }

        can_continue_ = pointer_ != end_;
    }

    void lexer::dot() noexcept
    {
        entity_ = *this;
        entity_.token_ = (pointer_ + 1 < end_) && (pointer_[1u] == '.') ? (pointer_ + 2 < end_) && (pointer_[2u] == '.') ?
                                                                         (pointer_ += 3, token_t::triple_dot) :
                                                                         (pointer_ += 2, token_t::double_dot) :
                                                                         token_t::dot;
        no_value();
    }

    void lexer::definition_symbol() noexcept
    {
        entity_ = *this;
        constexpr auto length = 3;
        if ((pointer_ + length < end_) && (pointer_[1] == ':') && (pointer_[2] == '='))
        {
            pointer_ += length;
            set_token(token_t::definition_symbol);
        }
        else
            unexpected_char();
    }

    void lexer::scan() noexcept
    {
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

                    set_token_and_increment(token_t::minus);
                    return;
                case '.':
                    dot();
                    return;
                case ':':
                    definition_symbol();
                    return;
                case ';':
                    set_token_and_increment(token_t::semicolon);
                    return;
                case ',':
                    set_token_and_increment(token_t::comma);
                    return;
                case '{':
                    set_token_and_increment(token_t::bracket_left);
                    return;
                case '}':
                    set_token_and_increment(token_t::bracket_right);
                    return;
                case '(':
                    set_token_and_increment(token_t::paren_left);
                    return;
                case ')':
                    set_token_and_increment(token_t::paren_right);
                    return;
                case '<':
                    set_token_and_increment(token_t::less_than);
                    return;
                case '>':
                    set_token_and_increment(token_t::greater_than);
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
