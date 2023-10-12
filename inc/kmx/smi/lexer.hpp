// SMI Parser
// Copyright (c) 2023 KMX Systems. All rights reserved.
#pragma once
#ifndef PCH
    #include <kmx/smi/token.hpp>
#endif

namespace kmx::smi
{
    using line_count_t = std::uint16_t;
    using tab_count_t = std::uint16_t;
    using column_count_t = std::uint16_t;
    using tab_size_t = std::uint8_t;

    class file_location
    {
    public:
        constexpr file_location(const tab_size_t tab_size = 4u): tab_size_(tab_size) {}

        const text_view_iterator_t& pointer() const noexcept { return pointer_; }
        void set_pointer(const text_view_iterator_t& item) noexcept { pointer_ = item; }

        const text_view_iterator_t& line_pointer() const noexcept { return line_pointer_; }
        void set_line_pointer(const text_view_iterator_t& item) noexcept { line_pointer_ = item; }

        tab_count_t tab_count() const noexcept { return tab_count_; }
        void set_tab_count(const tab_count_t item) noexcept { tab_count_ = item; }

        tab_size_t tab_size() const noexcept { return tab_size_; }
        void set_tab_size(const tab_size_t item) noexcept { tab_size_ = item; }

        line_count_t line_no() const noexcept { return line_no_ + 1u; }
        void set_line_no(const line_count_t item) noexcept { line_no_ = item; }

        column_count_t column_no() const noexcept;

        file_location& operator=(const file_location&) noexcept = default;

    public:
        text_view_iterator_t pointer_ {};
        text_view_iterator_t line_pointer_ {};
        line_count_t line_no_ {};
        tab_count_t tab_count_ {};
        tab_size_t tab_size_ {};
    };

    namespace token
    {
        class data: public file_location
        {
        public:
            using optional_value_t = std::optional<text_view_t>;
            using file_location::operator=;

            constexpr data(const tab_size_t tab_size = 4u): file_location(tab_size) {}

            const optional_value_t& value() const noexcept { return value_; }
            void set_value(const optional_value_t& item) noexcept { value_ = item; }

            token::id id() const noexcept { return id_; }
            void set_id(const token::id item) noexcept { id_ = item; }

            void reset_value() noexcept { value_.reset(); }

        private:
            optional_value_t value_ {};
            token::id id_ {};
        };

        std::ostream& operator<<(std::ostream& out, const data& item);
    }

    class lexer: private file_location
    {
    public:
        using tab_size_t = std::uint8_t;

        constexpr lexer() noexcept = default;
        lexer(const text_view_t& data, const tab_size_t tab_size = 4u) noexcept;

        void operator()(const text_view_t& data) noexcept;
        operator bool() const noexcept { return can_continue_; }
        void operator++() noexcept;

        const token::data& token() const noexcept { return token_; }

        tab_size_t tab_size() const noexcept { return token_.tab_size(); }
        void set_tab_size(const tab_size_t size) noexcept { token_.set_tab_size(size); }

    private:
        void unexpected_char() noexcept;
        void incomplete_token() noexcept;
        void no_value() noexcept;
        void set_token(const token::id token) noexcept;
        void set_token(const token::id token, const text_view_t& text) noexcept;
        void set_token_and_increment(const token::id token) noexcept;
        void set_token_and_increment(const token::id token, const text_view_t& text) noexcept;
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

        token::data token_ {};
        text_view_iterator_t end_ {};
        bool can_continue_ {};
    };
}
