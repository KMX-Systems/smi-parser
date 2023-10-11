// SMI Parser
// Copyright (c) 2023 KMX Systems. All rights reserved.
#pragma once
#ifndef PCH
    #include <optional>
    #include <ostream>
    #include <string_view>
#endif

namespace kmx::smi
{
    using text_view_t = std::string_view;
    using text_view_iterator_t = text_view_t::const_iterator;
}

namespace kmx::smi::token
{
    enum id
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

    const text_view_t& text_of(const id token);

    std::ostream& operator<<(std::ostream& out, const id token);
}
