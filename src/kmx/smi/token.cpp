// SMI Parser
// Copyright (c) 2023 KMX Systems. All rights reserved.
#include "kmx/smi/token.hpp"
#ifndef PCH
    #include <array>
    #include <utility>
#endif

namespace kmx::smi::token
{
    const text_view_t& text_of(const id token)
    {
        using array_t = std::array<text_view_t, std::to_underlying(id::write_syntax) + 1u>;
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

    std::ostream& operator<<(std::ostream& out, const id token)
    {
        auto& view = text_of(token);
        out.write(view.data(), view.size());
        return out;
    }
}
