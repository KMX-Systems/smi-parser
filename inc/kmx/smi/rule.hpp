#pragma once
#ifndef PCH
    #include <boost/spirit/home/x3/auxiliary/eol.hpp>
    #include <boost/spirit/home/x3/char/char.hpp>
    #include <boost/spirit/home/x3/char/char_class.hpp>
    #include <boost/spirit/home/x3/core/parse.hpp>
    #include <boost/spirit/home/x3/directive/lexeme.hpp>
    #include <boost/spirit/home/x3/directive/skip.hpp>
    #include <boost/spirit/home/x3/nonterminal/rule.hpp>
    #include <boost/spirit/home/x3/operator.hpp>
    #include <kmx/smi/token.hpp>
#endif

namespace kmx::smi::rule
{
    namespace x3 = ::boost::spirit::x3;

    constexpr x3::rule<struct alphabet_constraint_rule /* , ast::alphabet_constraint */> alphabet_constraint {"alphabet_constraint"};
    constexpr x3::rule<struct any_type_rule /* , ast::type::any */> any_type {"any_type"};
    constexpr x3::rule<struct assignment_rule /* , ast::assignment */> assignment {"assignment"};
    constexpr x3::rule<struct assignment_list_rule /* , ast::assignment_list */> assignment_list {"assignment_list"};
    constexpr x3::rule<struct binary_value_rule /* , ast::value::binary */> binary_value {"binary_value"};
    constexpr x3::rule<struct bit_or_object_identifier_value_rule /* , ast::value::bit_or_object_identifier */>
        bit_or_object_identifier_value {"bit_or_object_identifier_value"};
    constexpr x3::rule<struct bit_string_type_rule /* , ast::type::bit_string */> bit_string_type {"bit_string_type"};
    constexpr x3::rule<struct bits_type_rule /* , ast::type::bits */> bits_type {"bits_type"};
    constexpr x3::rule<struct boolean_type_rule /* , ast::type::boolean */> boolean_type {"boolean_type"};
    constexpr x3::rule<struct boolean_value_rule /* , ast::value::boolean */> boolean_value {"boolean_value"};
    constexpr x3::rule<struct builtin_type_rule /* , ast::type::builtin */> builtin_type {"builtin_type"};
    constexpr x3::rule<struct builtin_value_rule /* , ast::value::builtin */> builtin_value {"builtin_value"};
    constexpr x3::rule<struct choice_type_rule /* , ast::type::choice */> choice_type {"choice_type"};
    constexpr x3::rule<struct class__rule_rule /*, ast::class_*/> class_ {"class"};
    constexpr x3::rule<struct compliance_object_rule /* , ast::snmp::compliance_object */> compliance_object {"compliance_object"};
    constexpr x3::rule<struct component_constraint_rule /* , ast::component::constraint */> component_constraint {
        "component_constraint_type"};
    constexpr x3::rule<struct component_list_rule /* , ast::component::list */> component_list {"component_list_type"};
    constexpr x3::rule<struct component_list_tail_rule /* , ast::component::list_tail */> component_list_tail {"component_list_tail"};
    constexpr x3::rule<struct component_presence_rule /* , ast::component::presence */> component_presence {"component_presence"};
    constexpr x3::rule<struct component_value_presence_rule /* , ast::component::value_presence */> component_value_presence {
        "component_value_presence"};
    constexpr x3::rule<struct constraint_rule /* , ast::constraint */> constraint {"constraint"};
    constexpr x3::rule<struct constraint_list_rule /* , ast::constraint_list */> constraint_list {"constraint_list"};
    constexpr x3::rule<struct contact_part_rule /* , ast::snmp::contact_part */> contact_part {"snmp_contact_part"};
    constexpr x3::rule<struct contained_type_constraint_rule /* , ast::type::contained_constraint */> contained_type_constraint {
        "contained_type_constraint"};
    constexpr x3::rule<struct defined_macro_type_rule /* , ast::type::defined_macro_item */> defined_macro_type {"defined_macro_type"};
    constexpr x3::rule<struct defined_macro_name_rule /* , ast::type::defined_macro_name */> defined_macro_name {"defined_macro_name"};
    constexpr x3::rule<struct defined_type_rule /* , ast::type::defined */> defined_type {"defined_type"};
    constexpr x3::rule<struct defined_value_rule /* , ast::value::defined */> defined_value {"defined_value"};
    constexpr x3::rule<struct description_part_rule /* , ast::snmp::description_part */> description_part {"snmp_description_part"};
    constexpr x3::rule<struct element_type_rule /* , ast::type::element */> element_type {"element_type"};
    constexpr x3::rule<struct element_type_list_rule /* , ast::type::element_list */> element_type_list {"element_type_list"};
    constexpr x3::rule<struct enumerated_type_rule /* , ast::type::enumerated */> enumerated_type {"enumerated_type"};
    constexpr x3::rule<struct hexadecimal_value_rule /* , ast::hexadecimal_value */> hexadecimal_value {"hexadecimal_value"};
    constexpr x3::rule<struct identifier_string_list_rule /* , ast::identifier_string_list */> identifier_string_list {
        "identifier_string_list"};
    constexpr x3::rule<struct index_type_rule /* , ast::type::index */> index_type {"index_type"};
    constexpr x3::rule<struct index_value_rule /* , ast::value::index */> index_value {"index_value"};
    constexpr x3::rule<struct index_value_list_rule /* , ast::snmp::index_list */> index_value_list {"index_value_list"};
    constexpr x3::rule<struct inner_constraint_rule /* , ast::type::inner_constraint */> inner_constraint {"inner_constraint"};
    constexpr x3::rule<struct integer_type_rule /* , ast::type::integer */> integer_type {"integer_type"};
    constexpr x3::rule<struct lower_end_point_rule /* , ast::type::lower_end_point */> lower_end_point {"lower_end_point"};
    constexpr x3::rule<struct macro_body_rule /* , ast::macro::body */> macro_body {"macro_body"};
    constexpr x3::rule<struct macro_body_element_rule /* , ast::macro::body_element */> macro_body_element {"macro_body_element"};
    constexpr x3::rule<struct macro_defined_name_rule /* , ast::macro::defined_name */> macro_defined_name {"macro_defined_name"};
    constexpr x3::rule<struct macro_definition_rule /* , ast::macro::definition */> macro_definition {"macro_definition"};
    constexpr x3::rule<struct macro_reference_rule /* , ast::macro::reference */> macro_reference {"macro_reference"};
    constexpr x3::rule<struct mib_rule /* , ast::mib */> mib {"mib"};
    constexpr x3::rule<struct module_body_rule /* , ast::module::body */> module_body {"module_body"};
    constexpr x3::rule<struct module_definition_rule /* , ast::module::definition */> module_definition {"module_definition"};
    constexpr x3::rule<struct module_export_list_rule /* , ast::export_list */> module_export_list {"export_list"};
    constexpr x3::rule<struct module_export_part_rule /* , ast::snmp::module_export_part */> module_export_part {"snmp_module_export_part"};
    constexpr x3::rule<struct module_identifier_rule /* , ast::module::identifier */> module_identifier {"module_identifier"};
    constexpr x3::rule<struct module_import_list_rule /* , ast::import_list */> module_import_list {"import_list"};
    constexpr x3::rule<struct module_reference_rule /* , ast::module::reference */> module_reference {"module_reference"};
    constexpr x3::rule<struct module_tag_default_rule /* , ast::module::tag_default */> module_tag_default {"module_tag_default"};
    constexpr x3::rule<struct name_and_number_rule /* , ast::value::name_and_number */> name_and_number {"name_and_number"};
    constexpr x3::rule<struct named_number_rule /* , ast::type::named_number */> named_number {"named_number"};
    constexpr x3::rule<struct named_number_list_rule /* , ast::type::named_number_list */> named_number_list {"named_number_list"};
    constexpr x3::rule<struct name_or_number_rule /* , ast::value::name_or_number */> name_or_number {"name_or_number"};
    constexpr x3::rule<struct name_value_component_rule /* , ast::value::name_value_component */> name_value_component {
        "name_value_component"};
    constexpr x3::rule<struct name_value_list_rule /* , ast::value::name_value_list */> name_value_list {"name_value_list"};
    constexpr x3::rule<struct null_type_rule /* , ast::type::null */> null_type {"null_type"};
    constexpr x3::rule<struct null_value_rule /* , ast::value::null */> null_value {"null_value"};
    constexpr x3::rule<struct number_rule /* , ast::number */> number {"number"};
    constexpr x3::rule<struct number_value_rule /* , ast::value::number */> number_value {"number_value"};
    constexpr x3::rule<struct object_identifier_type_rule /* , ast::type::object_identifier */> object_identifier_type {
        "object_identifier_type"};
    constexpr x3::rule<struct object_identifier_value_rule /* , ast::value::object_identifier */> object_identifier_value {
        "object_identifier_value"};
    constexpr x3::rule<struct optional_or_default_element_rule /* , ast::type::optional_or_default_element */> optional_or_default_element {
        "optional_or_default_element"};
    constexpr x3::rule<struct organization_part_rule /* , ast::snmp::organization_part */> organization_part {"snmp_organization_part"};
    constexpr x3::rule<struct real_type_rule /* , ast::type::real */> real_type {"real_type"};
    constexpr x3::rule<struct refer_part_rule /* , ast::snmp::refer_part */> refer_part {"snmp_refer_part"};
    constexpr x3::rule<struct revision_part_rule /* , ast::snmp::revision_part */> revision_part {"snmp_revision_part"};
    constexpr x3::rule<struct selection_type_rule /* , ast::type::selection */> selection_type {"selection_type"};
    constexpr x3::rule<struct sequence_of_type_rule /* , ast::type::sequence_of */> sequence_of_type {"sequence_of_type"};
    constexpr x3::rule<struct sequence_type_rule /* , ast::type::sequence */> sequence_type {"sequence_type"};
    constexpr x3::rule<struct set_of_type_rule /* , ast::type::set_of */> set_of_type {"set_of_type"};
    constexpr x3::rule<struct set_type_rule /* , ast::type::set */> set_type {"set_type"};
    constexpr x3::rule<struct size_constraint_rule /* , ast::type::size_constraint */> size_constraint {"size_constraint"};
    constexpr x3::rule<struct snmp_access_part_rule /* , ast::snmp::access_part */> snmp_access_part {"snmp_access_part"};
    constexpr x3::rule<struct snmp_compliance_group_rule /* , ast::snmp::compliance_group */> snmp_compliance_group {
        "snmp_compliance_group"};
    constexpr x3::rule<struct snmp_compliance_object_rule /* , ast::snmp::compliance_object */> snmp_compliance_object {
        "snmp_compliance_object"};
    constexpr x3::rule<struct snmp_compliance_part_rule /* , ast::snmp::compliance_part */> snmp_compliance_part {"snmp_compliance_part"};
    constexpr x3::rule<struct snmp_creation_part_rule /* , ast::snmp::creation_part */> snmp_creation_part {"snmp_creation_part"};
    constexpr x3::rule<struct snmp_def_var_part_rule /* , ast::snmp::def_var_part */> snmp_def_var_part {"snmp_def_var_part"};
    constexpr x3::rule<struct snmp_display_part_rule /* , ast::snmp::display_part */> snmp_display_part {"snmp_display_part"};
    constexpr x3::rule<struct snmp_enterprise_part_rule /* , ast::snmp::enterprise_part */> snmp_enterprise_part {"snmp_enterprise_part"};
    constexpr x3::rule<struct snmp_index_part_rule /* , ast::snmp::index_part */> snmp_index_part {"snmp_index_part"};
    constexpr x3::rule<struct snmp_mandatory_part_rule /* , ast::snmp::mandatory_part */> snmp_mandatory_part {"snmp_mandatory_part"};
    constexpr x3::rule<struct snmp_module_import_rule /* , ast::snmp::module_import */> snmp_module_import {"snmp_module_import"};
    constexpr x3::rule<struct snmp_module_part_rule /* , ast::snmp::module_part */> snmp_module_part {"snmp_module_part"};
    constexpr x3::rule<struct snmp_module_support_part_rule /* , ast::snmp::module_support_part */> snmp_module_support_part {
        "snmp_module_support_part"};
    constexpr x3::rule<struct snmp_notification_part_rule /* , ast::snmp::notification_part */> snmp_notification_part {
        "snmp_notification_part"};
    constexpr x3::rule<struct snmp_object_part_rule /* , ast::snmp::object_part */> snmp_object_part {"snmp_object_part"};
    constexpr x3::rule<struct snmp_product_release_part_rule /* , ast::snmp::product_release_part */> snmp_product_release_part {
        "snmp_product_release_part"};
    constexpr x3::rule<struct snmp_status_part_rule /* , ast::snmp::status_part */> snmp_status_part {"snmp_status_part"};
    constexpr x3::rule<struct snmp_syntax_part_rule /* , ast::snmp::syntax_part */> snmp_syntax_part {"snmp_syntax_part"};
    constexpr x3::rule<struct snmp_unit_part_rule /* , ast::snmp::unit_part */> snmp_unit_part {"snmp_unit_part"};
    constexpr x3::rule<struct snmp_update_part_rule /* , ast::snmp::update_part */> snmp_update_part {"snmp_update_part"};
    constexpr x3::rule<struct snmp_variation_part_rule /* , ast::snmp::variation_part */> snmp_variation_part {"snmp_variation_part"};
    constexpr x3::rule<struct snmp_var_part_rule /* , ast::snmp::var_part */> snmp_var_part {"snmp_var_part"};
    constexpr x3::rule<struct snmp_write_syntax_part_rule /* , ast::snmp::write_syntax_part */> snmp_write_syntax_part {
        "snmp_write_syntax_part"};
    constexpr x3::rule<struct special_real_value_rule /* , ast::value::special_real */> special_real_value {"special_real_value"};
    constexpr x3::rule<struct string_type_rule /* , ast::type::string */> string_type {"string_type"};
    constexpr x3::rule<struct string_value_rule /* , ast::value::string */> string_value {"string_value"};
    constexpr x3::rule<struct symbol_rule /* , ast::symbol */> symbol {"symbol"};
    constexpr x3::rule<struct symbol_list_rule /* , ast::symbol_list */> symbol_list {"symbol_list"};
    constexpr x3::rule<struct symbols_from_module_rule /* , ast::module::symbol_from_module */> symbols_from_module {"symbols_from_module"};
    constexpr x3::rule<struct tag_rule /* , ast::type::tag */> tag {"tag"};
    constexpr x3::rule<struct tag_default_rule /* , ast::tag_default */> tag_default {"tag_default"};
    constexpr x3::rule<struct tagged_type_rule /* , ast::type::tagged */> tagged_type {"tagged_type"};
    constexpr x3::rule<struct type_assignment_rule /* , ast::type::assignment */> type_assignment {"type_assignment"};
    constexpr x3::rule<struct type_rule /* , ast::type::item */> type {"type"};
    constexpr x3::rule<struct upper_end_point_rule /* , ast::type::upper_end_point */> upper_end_point {"upper_end_point"};
    constexpr x3::rule<struct value_assignment_rule /* , ast::value::assignment */> value_assignment {"value_assignment"};
    constexpr x3::rule<struct value_rule /* , ast::value::item */> value {"value"};
    constexpr x3::rule<struct value_constraint_rule /* , ast::type::value_constraint */> value_constraint {"value_constraint"};
    constexpr x3::rule<struct value_constraint_list_rule /* , ast::type::value_constraint_list */> value_constraint_list {
        "value_constraint_list"};
    constexpr x3::rule<struct value_list_rule /* , ast::value::list */> value_list {"value_list"};
    constexpr x3::rule<struct value_or_constraint_list_rule /* , ast::type::value_or_constraint_list */> value_or_constraint_list {
        "value_or_constraint_list_type"};
    constexpr x3::rule<struct value_range_rule /* , ast::type::value_range */> value_range {"value_range"};

    using x3::char_;
    using x3::eol;

    template <typename T>
    constexpr auto operator+(T e) noexcept -> std::enable_if_t<std::is_enum<T>::value, std::underlying_type_t<T>>
    {
        return static_cast<std::underlying_type_t<T>>(e);
    }

    struct dummy_token_parser: x3::parser<dummy_token_parser>
    {
        using attribute_type = token::id;
        static const bool has_attribute = true;

        constexpr dummy_token_parser(const token::id tok): tok(tok) {}

        template <typename It, typename Ctx, typename A>
        bool parse(It& first, const It& last, const Ctx& /*ctx*/, x3::unused_type, A& attr) const
        {
            if (first != last && *first == tok)
            {
                attr = *first;
                ++first;
                return true;
            }

            return false;
        }

        token::id tok;
    };

    using tp = dummy_token_parser;

    namespace tk
    {
        // symbol
        constexpr auto brace_left = tp{token::id::brace_left};
        constexpr auto brace_right = tp{token::id::brace_right};
        constexpr auto bracket_left = tp{token::id::bracket_left};
        constexpr auto bracket_right = tp{token::id::bracket_right};
        constexpr auto paren_left = tp{token::id::paren_left};
        constexpr auto paren_right = tp{token::id::paren_right};
        constexpr auto quote = tp{token::id::quote};
        constexpr auto double_quote = tp{token::id::double_quote};
        constexpr auto less_than = tp{token::id::less_than};
        constexpr auto greater_than = tp{token::id::greater_than};
        constexpr auto comma = tp{token::id::comma};
        constexpr auto dot = tp{token::id::dot};
        constexpr auto minus = tp{token::id::minus};
        constexpr auto pipe = tp{token::id::pipe};
        constexpr auto semicolon = tp{token::id::semicolon};
        constexpr auto underscore = tp{token::id::underscore};
        constexpr auto double_dot = tp{token::id::double_dot};
        constexpr auto triple_dot = tp{token::id::triple_dot};
        constexpr auto definition_symbol = tp{token::id::definition_symbol};

        // string
        constexpr auto binary_string = tp{token::id::binary_string};
        constexpr auto hexadecimal_string = tp{token::id::hexadecimal_string};
        constexpr auto identifier_string = tp{token::id::identifier_string};
        constexpr auto number_string = tp{token::id::number_string};
        constexpr auto quoted_string = tp{token::id::quoted_string};

        // keyword
        constexpr auto absent = tp{token::id::absent};
        constexpr auto access = tp{token::id::access};
        constexpr auto agent_capabilities = tp{token::id::agent_capabilities};
        constexpr auto any = tp{token::id::any};
        constexpr auto application = tp{token::id::application};
        constexpr auto augments = tp{token::id::augments};
        constexpr auto begin = tp{token::id::begin};
        constexpr auto bit = tp{token::id::bit};
        constexpr auto bits = tp{token::id::bits};
        constexpr auto boolean = tp{token::id::boolean};
        constexpr auto by = tp{token::id::by};
        constexpr auto choice = tp{token::id::choice};
        constexpr auto component = tp{token::id::component};
        constexpr auto components = tp{token::id::components};
        constexpr auto contact_info = tp{token::id::contact_info};
        constexpr auto creation_requires = tp{token::id::creation_requires};
        constexpr auto default_ = tp{token::id::default_};
        constexpr auto defined = tp{token::id::defined};
        constexpr auto definitions = tp{token::id::definitions};
        constexpr auto defval = tp{token::id::defval};
        constexpr auto description = tp{token::id::description};
        constexpr auto display_hint = tp{token::id::display_hint};
        constexpr auto end = tp{token::id::end};
        constexpr auto enterprise = tp{token::id::enterprise};
        constexpr auto enumerated = tp{token::id::enumerated};
        constexpr auto explicit_ = tp{token::id::explicit_};
        constexpr auto exports = tp{token::id::exports};
        constexpr auto false_ = tp{token::id::false_};
        constexpr auto from = tp{token::id::from};
        constexpr auto group = tp{token::id::group};
        constexpr auto identifier = tp{token::id::identifier};
        constexpr auto implicit = tp{token::id::implicit};
        constexpr auto implied = tp{token::id::implied};
        constexpr auto imports = tp{token::id::imports};
        constexpr auto includes = tp{token::id::includes};
        constexpr auto index = tp{token::id::index};
        constexpr auto integer = tp{token::id::integer};
        constexpr auto last_updated = tp{token::id::last_updated};
        constexpr auto macro = tp{token::id::macro};
        constexpr auto mandatory_groups = tp{token::id::mandatory_groups};
        constexpr auto max_access = tp{token::id::max_access};
        constexpr auto max = tp{token::id::max};
        constexpr auto min_access = tp{token::id::min_access};
        constexpr auto min = tp{token::id::min};
        constexpr auto minus_infinity = tp{token::id::minus_infinity};
        constexpr auto module_compliance = tp{token::id::module_compliance};
        constexpr auto module_identity = tp{token::id::module_identity};
        constexpr auto module = tp{token::id::module};
        constexpr auto notification_group = tp{token::id::notification_group};
        constexpr auto notifications = tp{token::id::notifications};
        constexpr auto notification_type = tp{token::id::notification_type};
        constexpr auto null = tp{token::id::null};
        constexpr auto object_group = tp{token::id::object_group};
        constexpr auto object_identity = tp{token::id::object_identity};
        constexpr auto object = tp{token::id::object};
        constexpr auto objects = tp{token::id::objects};
        constexpr auto object_type = tp{token::id::object_type};
        constexpr auto octet = tp{token::id::octet};
        constexpr auto of = tp{token::id::of};
        constexpr auto optional = tp{token::id::optional};
        constexpr auto organization = tp{token::id::organization};
        constexpr auto plus_infinity = tp{token::id::plus_infinity};
        constexpr auto present = tp{token::id::present};
        constexpr auto private_ = tp{token::id::private_};
        constexpr auto product_release = tp{token::id::product_release};
        constexpr auto real = tp{token::id::real};
        constexpr auto reference = tp{token::id::reference};
        constexpr auto revision = tp{token::id::revision};
        constexpr auto sequence = tp{token::id::sequence};
        constexpr auto set = tp{token::id::set};
        constexpr auto size = tp{token::id::size};
        constexpr auto status = tp{token::id::status};
        constexpr auto string = tp{token::id::string};
        constexpr auto supports = tp{token::id::supports};
        constexpr auto syntax = tp{token::id::syntax};
        constexpr auto tags = tp{token::id::tags};
        constexpr auto textual_convention = tp{token::id::textual_convention};
        constexpr auto trap_type = tp{token::id::trap_type};
        constexpr auto true_ = tp{token::id::true_};
        constexpr auto units = tp{token::id::units};
        constexpr auto universal = tp{token::id::universal};
        constexpr auto variables = tp{token::id::variables};
        constexpr auto variation = tp{token::id::variation};
        constexpr auto with = tp{token::id::with};
        constexpr auto write_syntax = tp{token::id::write_syntax};
    }

    constexpr auto alphabet_constraint_def = tk::from >> value_constraint_list;
    constexpr auto any_type_def = tk::any >> -(tk::defined >> tk::by >> tk::identifier_string);
    constexpr auto assignment_def = (macro_definition | type_assignment | value_assignment) >> -tk::semicolon;
    constexpr auto assignment_list_def = +assignment;
    constexpr auto binary_value_def = tk::binary_string;
    constexpr auto bit_def = name_value_list;
    constexpr auto bit_or_object_identifier_value_def = name_value_list;
    constexpr auto bit_string_type_def = tk::bit >> tk::string >> -value_or_constraint_list;
    constexpr auto bits_type_def = tk::bits >> -value_or_constraint_list;
    constexpr auto boolean_type_def = tk::boolean;
    constexpr auto boolean_value_def = tk::true_ | tk::false_;
    constexpr auto builtin_type_def = null_type | boolean_type | real_type | integer_type | object_identifier_type | string_type |
                                      bit_string_type | bits_type | sequence_type | sequence_of_type | set_type | set_of_type |
                                      choice_type | enumerated_type | selection_type | tagged_type | any_type;
    constexpr auto builtin_value_def = null_value | boolean_value | special_real_value | number | binary_value | hexadecimal_value |
                                       string_value | bit_or_object_identifier_value;
    constexpr auto choice_type_def = tk::choice >> tk::brace_left >> -element_type_list >> tk::brace_right;
    constexpr auto class__def = tk::universal | tk::application | tk::private_;
    constexpr auto snmp_compliance_group_def = tk::group >> value >> description_part;
    constexpr auto snmp_compliance_object_def =
        tk::object >> value >> -snmp_syntax_part >> -snmp_write_syntax_part >> -snmp_access_part >> description_part;
    constexpr auto component_constraint_def = (tk::identifier_string >> -component_value_presence) | component_value_presence;
    constexpr auto component_list_def =
        (tk::brace_left >> (component_constraint >> *component_list_tail) | (tk::triple_dot >> component_list_tail) >> tk::brace_right);
    constexpr auto component_list_tail_def = tk::comma >> -component_constraint;
    constexpr auto component_presence_def = tk::present | tk::absent | tk::optional;
    constexpr auto component_value_presence_def = (value_or_constraint_list >> -component_presence) | component_presence;
    constexpr auto constraint_def = value_constraint | size_constraint | alphabet_constraint | contained_type_constraint | inner_constraint;
    constexpr auto constraint_list_def = tk::paren_left >> constraint >> (tk::pipe >> *constraint) >> tk::paren_right;
    constexpr auto contact_part_def = tk::contact_info >> tk::quoted_string;
    constexpr auto contained_type_constraint_def = tk::includes >> type;
    constexpr auto defined_macro_type_def = -module_reference >> tk::identifier_string >> -value_or_constraint_list;
    constexpr auto defined_macro_name_def = tk::module_identity | tk::object_identity | tk::object_type | tk::notification_type |
                                            tk::trap_type | tk::textual_convention | tk::notification_group | tk::module_compliance |
                                            tk::agent_capabilities;
    constexpr auto defined_type_def = -module_reference >> tk::identifier_string >> -value_or_constraint_list;
    constexpr auto defined_value_def = -module_reference >> tk::identifier_string;
    constexpr auto description_part_def = tk::description >> tk::quoted_string;
    constexpr auto element_type_def = -tk::identifier_string >> (type >> -optional_or_default_element) | (tk::components >> tk::of >> type);
    constexpr auto element_type_list_def = tk::brace_left >> element_type >> *(tk::comma >> element_type) >> tk::brace_right;
    constexpr auto enumerated_type_def = tk::enumerated >> named_number_list;
    constexpr auto hexadecimal_value_def = tk::hexadecimal_string;
    constexpr auto identifier_string_list_def = (tk::identifier_string >> *(tk::comma >> tk::identifier_string));
    constexpr auto index_type_def = integer_type | string_type | object_identifier_type;
    constexpr auto index_value_def = value | (tk::implied >> value) | index_type;
    constexpr auto index_value_list_def = index_value >> *(tk::comma >> index_value);
    constexpr auto inner_constraint_def = tk::with >> (tk::component >> value_or_constraint_list) | (tk::components >> component_list);
    constexpr auto integer_type_def = tk::integer >> -value_or_constraint_list;
    constexpr auto lower_end_point_def = value | tk::min;
    constexpr auto macro_body_def = (tk::begin >> macro_body_element >> tk::end) | (module_reference >> macro_reference);
    constexpr auto macro_body_element_def = tk::paren_left | tk::paren_right | tk::pipe | tk::definition_symbol | tk::integer | tk::real |
                                            tk::boolean | tk::null | tk::bit | tk::octet | tk::string | tk::object | tk::identifier |
                                            tk::identifier_string | tk::quoted_string;
    constexpr auto macro_defined_name_def = tk::module_identity | tk::object_identity | tk::object_type | tk::notification_type |
                                            tk::trap_type | tk::textual_convention | tk::object_group | tk::notification_group |
                                            tk::agent_capabilities;
    constexpr auto macro_definition_def = macro_reference >> tk::macro >> tk::definition_symbol >> macro_body;
    constexpr auto macro_reference_def = tk::identifier_string | defined_macro_name;
    constexpr auto mib_def = +module_definition;
    constexpr auto module_body_def = -module_export_list >> -module_import_list >> assignment_list;
    constexpr auto module_definition_def =
        tk::identifier_string >> tk::definitions >> -module_tag_default >> tk::definition_symbol >> tk::begin >> module_body >> tk::end;
    constexpr auto module_export_list_def = tk::exports >> symbol_list >> tk::end;
    constexpr auto module_export_part_def =
        tk::supports >> snmp_module_import >> tk::includes >> tk::brace_left >> value_list >> tk::brace_right >> *snmp_variation_part;
    constexpr auto module_identifier_def = tk::identifier_string >> -object_identifier_value;
    constexpr auto module_import_list_def = tk::imports >> *symbols_from_module;
    constexpr auto module_reference_def = tk::identifier >> tk::dot;
    constexpr auto module_tag_default_def = (tk::explicit_ | tk::implicit) >> tk::tags;
    constexpr auto name_and_number_def = tk::identifier_string >> tk::paren_left >> (tk::number_string | defined_value) >> tk::paren_right;
    constexpr auto named_number_def = tk::identifier_string >> tk::paren_left >> number >> tk::paren_right;
    constexpr auto named_number_list_def = tk::brace_left >> named_number >> *(tk::comma >> named_number) >> tk::brace_right;
    constexpr auto name_or_number_def = tk::number_string | tk::identifier_string | name_and_number;
    constexpr auto name_value_component_def = -tk::comma >> name_or_number;
    constexpr auto name_value_list_def = tk::brace_left >> *name_value_component >> tk::brace_right;
    constexpr auto null_type_def = tk::null;
    constexpr auto null_value_def = tk::null;
    constexpr auto number_def = number_value | binary_value | hexadecimal_value | defined_value;
    constexpr auto number_value_def = tk::minus >> tk::number_string;
    constexpr auto object_identifier_type_def = tk::object >> tk::identifier;
    constexpr auto object_identifier_value_def = name_value_list;
    constexpr auto optional_or_default_element_def = tk::optional | (tk::default_ >> -tk::identifier_string >> value);
    constexpr auto organization_part_def = tk::organization >> tk::quoted_string;
    constexpr auto real_type_def = tk::real;
    constexpr auto refer_part_def = tk::reference >> tk::quoted_string;
    constexpr auto revision_part_def = tk::revision >> value >> tk::description >> tk::quoted_string;
    constexpr auto selection_type_def = tk::identifier_string >> tk::less_than >> type;
    constexpr auto sequence_of_type_def = tk::sequence >> -constraint_list >> tk::of >> type;
    constexpr auto sequence_type_def = tk::sequence >> tk::brace_left >> -element_type_list >> tk::brace_right;
    constexpr auto set_of_type_def = tk::set >> -size_constraint >> tk::of >> type;
    constexpr auto set_type_def = tk::set >> tk::brace_left >> -element_type_list >> tk::brace_right;
    constexpr auto size_constraint_def = tk::size >> value_constraint_list;
    constexpr auto snmp_access_part_def = (tk::access >> tk::identifier_string) | ((tk::max_access | tk::min_access) >> tk::identifier_string);
    constexpr auto snmp_compliance_part_def = snmp_compliance_group | compliance_object;
    constexpr auto snmp_creation_part_def = tk::creation_requires >> tk::brace_left >> value_list >> tk::brace_right;
    constexpr auto snmp_def_var_part_def = tk::defval >> tk::brace_left >> value >> tk::brace_right;
    constexpr auto snmp_display_part_def = tk::display_hint >> tk::quoted_string;
    constexpr auto snmp_enterprise_part_def = tk::enterprise >> value;
    constexpr auto snmp_index_part_def =
        (tk::index >> tk::brace_left >> index_value_list >> tk::brace_right) | (tk::augments >> tk::brace_left >> value >> tk::brace_right);
    constexpr auto snmp_mandatory_part_def = tk::mandatory_groups >> value_list;
    constexpr auto snmp_module_import_def = module_identifier;
    constexpr auto snmp_module_part_def = tk::module >> -snmp_module_import >> -snmp_mandatory_part >> *snmp_compliance_part;
    constexpr auto snmp_module_support_part_def =
        tk::supports >> snmp_module_import >> tk::includes >> tk::brace_left >> value_list >> tk::brace_right >> *snmp_variation_part;
    constexpr auto snmp_notification_part_def = tk::notifications >> tk::brace_left >> value_list >> tk::brace_right;
    constexpr auto snmp_object_part_def = tk::objects >> tk::brace_left >> value_list >> tk::brace_right;
    constexpr auto snmp_product_release_part_def = tk::product_release >> tk::quoted_string;
    constexpr auto snmp_variation_part_def =
        tk::variation >> value >> -snmp_syntax_part >> -snmp_write_syntax_part >> -snmp_access_part >> description_part;
    constexpr auto snmp_var_part_def = tk::variables >> tk::brace_left >> value_list >> tk::brace_right;
    constexpr auto snmp_syntax_part_def = tk::syntax >> type;
    constexpr auto snmp_write_syntax_part_def = tk::write_syntax >> type;
    constexpr auto special_real_value_def = tk::plus_infinity | tk::minus_infinity;
    constexpr auto snmp_status_part_def = tk::status >> tk::identifier_string;
    constexpr auto string_type_def = tk::octet >> tk::string >> constraint_list;
    constexpr auto string_value_def =tk:: quoted_string;
    constexpr auto symbol_def = tk::identifier_string | defined_macro_name;
    constexpr auto symbol_list_def = symbol >> *(tk::comma >> symbol);
    constexpr auto symbols_from_module_def = symbol_list >> tk::from >> tk::identifier_string;
    constexpr auto tag_def = tk::bracket_left >> -class_ >> tk::number_string >> tk::bracket_right;
    constexpr auto tagged_type_def = tag >> -(tk::explicit_ | tk::implicit) >> type;
    constexpr auto type_assignment_def = tk::identifier_string >> tk::definition_symbol >> type;
    constexpr auto type_def = builtin_type | defined_type | defined_macro_type;
    constexpr auto snmp_unit_part_def = tk::units >> tk::quoted_string;
    constexpr auto snmp_update_part_def = tk::last_updated >> tk::quoted_string;
    constexpr auto upper_end_point_def = value | tk::max;
    constexpr auto value_assignment_def = tk::identifier_string >> type >> tk::definition_symbol >> value;
    constexpr auto value_constraint_def = lower_end_point >> -value_range;
    constexpr auto value_constraint_list_def = tk::paren_left >> value_constraint >> (tk::pipe >> *value_constraint) >> tk::paren_right;
    constexpr auto value_def = builtin_value | defined_value;
    constexpr auto value_list_def = value >> *(tk::comma >> value);
    constexpr auto value_or_constraint_list_def = named_number_list | value_constraint_list;
    constexpr auto value_range_def = tk::less_than >> tk::double_dot >> tk::less_than >> upper_end_point;

    //    constexpr auto ignore_comment = x3::lexeme[tk::minus >> *(char_ - eol) >> +eol];
    //    constexpr auto rules = x3::rule<struct rules, std::string> {"rules"} = x3::skip(x3::space)[mib];

    //constexpr auto rules = mib;

    BOOST_SPIRIT_DEFINE(alphabet_constraint, any_type, assignment, assignment_list, binary_value, bit_or_object_identifier_value,
                        bit_string_type, bits_type, boolean_type, boolean_value, builtin_type, builtin_value, choice_type, class_,
                        component_constraint, component_list, component_list_tail, component_presence, component_value_presence, constraint,
                        constraint_list, contact_part, contained_type_constraint, defined_macro_type, defined_macro_name, defined_type,
                        defined_value, description_part, element_type, element_type_list, enumerated_type, hexadecimal_value,
                        identifier_string_list, index_type, index_value, index_value_list, inner_constraint, integer_type, lower_end_point,
                        macro_body, macro_body_element, macro_defined_name, macro_definition, macro_reference, mib, module_body,
                        module_definition, module_export_list, module_export_part, module_identifier, module_import_list, module_reference,
                        module_tag_default);

    BOOST_SPIRIT_DEFINE(name_and_number, named_number, named_number_list, name_or_number, name_value_component, name_value_list, null_type,
                        null_value, number, number_value, object_identifier_type, object_identifier_value, optional_or_default_element,
                        organization_part, real_type, refer_part, revision_part, selection_type, sequence_of_type, sequence_type,
                        set_of_type, set_type, size_constraint, snmp_access_part, snmp_compliance_group, snmp_compliance_object,
                        snmp_compliance_part, snmp_creation_part);

    BOOST_SPIRIT_DEFINE(snmp_def_var_part, snmp_display_part, snmp_enterprise_part, snmp_index_part, snmp_mandatory_part,
                        snmp_module_import, snmp_module_part, snmp_module_support_part, snmp_notification_part, snmp_object_part,
                        snmp_product_release_part, snmp_status_part, snmp_syntax_part, snmp_unit_part, snmp_update_part,
                        snmp_variation_part, snmp_var_part, snmp_write_syntax_part, special_real_value, string_type, string_value, symbol,
                        symbol_list, symbols_from_module, tag, tagged_type, type_assignment, type, upper_end_point, value_assignment, value,
                        value_constraint, value_constraint_list, value_list, value_or_constraint_list, value_range);
}

namespace kmx::smi
{
    template <typename Iterator>
    bool parse1(Iterator& first, Iterator last /*, ast::mib& result*/)
    {
        return boost::spirit::x3::parse(first, last, rule::mib);
        // return ::boost::spirit::x3::parse(first, last, grammar::rules, result);
        //   return ::boost::spirit::x3::parse(first, last, grammar::rules, grammar::ignore_comment);
        //   return ::boost::spirit::x3::parse(first, last, grammar::rules, grammar::ignore_comment, result);
    }
}
