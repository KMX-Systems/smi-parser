// SMI Parser
// Copyright (c) 2023 KMX Systems. All rights reserved.
#pragma once
#ifndef PCH
    #include <optional>
    #include <string_view>
#endif

namespace kmx::smi
{
    enum class token_t
    {
        // error
        unexpected_char,
        incomplete,

        // symbol
        brace_left,
        brace_right,
        bracket_left,
        bracket_right,
        paren_left,
        paren_right,
        quote,
        double_quote,
        less_than,
        greater_than,
        comma,
        dot,
        minus,
        pipe,
        semicolon,
        underscore,
        double_dot,
        triple_dot,
        definition_symbol,

        // string
        binary_string,
        hexadecimal_string,
        identifier_string,
        number_string,
        quoted_string,

        // keyword
        absent,
        access,
        agent_capabilities,
        any,
        application,
        augments,
        begin,
        bit,
        bits,
        boolean,
        by,
        choice,
        component,
        components,
        contact_info,
        creation_requires,
        default_,
        defined,
        definitions,
        defval,
        description,
        display_hint,
        end,
        enterprise,
        enumerated,
        explicit_,
        exports,
        false_,
        from,
        group,
        identifier,
        implicit,
        implied,
        imports,
        includes,
        index,
        integer,
        last_updated,
        macro,
        mandatory_groups,
        max_access,
        max,
        min_access,
        min,
        minus_infinity,
        module_compliance,
        module_identity,
        module,
        notification_group,
        notifications,
        notification_type,
        null,
        object_group,
        object_identity,
        object,
        objects,
        object_type,
        octet,
        of,
        optional,
        organization,
        plus_infinity,
        present,
        private_,
        product_release,
        real,
        reference,
        revision,
        sequence,
        set,
        size,
        status,
        string,
        supports,
        syntax,
        tags,
        textual_convention,
        trap_type,
        true_,
        units,
        universal,
        variables,
        variation,
        with,
        write_syntax,
    };

    using text_view_t = std::string_view;
    using text_view_iterator_t = text_view_t::const_iterator;
    using optional_token_value_view_t = std::optional<text_view_t>;

    std::optional<token_t> find(const text_view_t& view);
    const text_view_t& text_of(const token_t token);

    struct data
    {
        text_view_iterator_t pointer_ {};
        text_view_iterator_t line_pointer_ {};
        std::size_t line_no_ {};
        std::size_t tab_count_ {};

        data& operator=(const data&) noexcept = default;
    };

    class lexer: private data
    {
    public:
        constexpr lexer() noexcept = default;
        lexer(const text_view_t& data) noexcept;

        void operator()(const text_view_t& data) noexcept;
        operator bool() const noexcept { return can_continue_; }
        void operator++() noexcept;

        token_t token() const noexcept { return entity_.token; }
        const optional_token_value_view_t& token_value() const noexcept { return entity_.token_value; }

        std::size_t line_no() const noexcept { return entity_.line_no_ + 1u; }
        std::size_t column_no() const noexcept { return entity_.column_no(); }

        std::uint8_t tab_size() const noexcept { return entity_.tab_size; }
        void set_tab_size(const std::uint8_t item) noexcept { entity_.tab_size = item; }

    private:
        struct entity: data
        {
            using data::operator=;

            optional_token_value_view_t token_value {};
            token_t token {};
            std::uint8_t tab_size {4u};

            std::size_t column_no() const noexcept
            {
                return static_cast<std::size_t>(pointer_ - line_pointer_) + (tab_size - 1u) * tab_count_ + 1u;
            }
        };

        void unexpected_char() noexcept;
        void incomplete_token() noexcept;
        void no_value() noexcept;
        void set_token(const token_t token) noexcept;
        void set_token(const token_t token, const text_view_t& text) noexcept;
        void set_token_and_increment(const token_t token) noexcept;
        void set_token_and_increment(const token_t token, const text_view_t& text) noexcept;
        void new_line() noexcept;
        void space() noexcept;
        void comment() noexcept;
        void dot() noexcept;
        void definition_symbol() noexcept;
        void quoted_string() noexcept;
        void check_number() noexcept;
        void check_special_number() noexcept;
        void continue_identifier() noexcept;
        void identifier() noexcept;
        void try_match_keyword() noexcept;
        void upper_case_string() noexcept;
        void scan() noexcept;
        text_view_t create_text_view() noexcept;

        entity entity_ {};
        text_view_iterator_t end_ {};
        bool can_continue_ {};
    };
}
