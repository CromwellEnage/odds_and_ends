// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION_FWD_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION_FWD_HPP

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct function_result_type_ext;

    template <typename T>
    struct function_result_type;

    template <typename T>
    struct function_parameter_types_ext;

    template <typename F, typename ClassTransform>
    struct function_parameter_types;

    template <typename T>
    struct is_reference_wrapper;

    template <typename T>
    struct allocator_pointer_of;

    template <typename T>
    using allocator_pointer_of_t = typename ::odds_and_ends
    ::static_introspection::allocator_pointer_of<T>::type;

    template <typename T1, typename T2>
    struct is_allocator_pointer_of;

    template <typename T>
    struct allocator_void_pointer_of;

    template <typename T>
    using allocator_void_pointer_of_t = typename ::odds_and_ends
    ::static_introspection::allocator_void_pointer_of<T>::type;

    template <typename T>
    struct allocator_difference_of;

    template <typename T>
    using allocator_difference_of_t = typename ::odds_and_ends
    ::static_introspection::allocator_difference_of<T>::type;

    template <typename T>
    struct allocator_size_of;

    template <typename T>
    using allocator_size_of_t = typename ::odds_and_ends
    ::static_introspection::allocator_size_of<T>::type;

    template <typename T>
    struct allocator_propagate_on_container_copy_assignment;

    template <typename T>
    struct allocator_propagate_on_container_move_assignment;

    template <typename T>
    struct allocator_propagate_on_container_swap;

    template <typename T>
    struct allocator_is_always_equal;

    template <typename T>
    struct has_stable_iterators;

    template <typename T>
    struct iterator_category_of;

    template <typename T>
    using iterator_category_of_t = typename ::odds_and_ends
    ::static_introspection::iterator_category_of<T>::type;

    template <typename T1, typename T2>
    struct is_iterator_category_of;

    template <typename T>
    struct iterator_traversal_of;

    template <typename T>
    using iterator_traversal_of_t = typename ::odds_and_ends
    ::static_introspection::iterator_traversal_of<T>::type;

    template <typename T1, typename T2>
    struct is_iterator_traversal_of;

    template <typename T>
    struct iterator_difference_of;

    template <typename T>
    using iterator_difference_of_t = typename ::odds_and_ends
    ::static_introspection::iterator_difference_of<T>::type;

    template <typename T>
    struct has_iterator_reference;

    template <typename T>
    struct iterator_reference_of;

    template <typename T>
    using iterator_reference_of_t = typename ::odds_and_ends
    ::static_introspection::iterator_reference_of<T>::type;

    template <typename T>
    struct has_iterator_reference;

    template <typename T>
    struct iterator_reference_of;

    template <typename T>
    using iterator_reference_of_t = typename ::odds_and_ends
    ::static_introspection::iterator_reference_of<T>::type;

    template <typename T1, typename T2>
    struct is_iterator_reference_of;

    template <typename T>
    struct has_iterator_value;

    template <typename T>
    struct iterator_value_of;

    template <typename T>
    using iterator_value_of_t = typename ::odds_and_ends
    ::static_introspection::iterator_value_of<T>::type;

    template <typename T1, typename T2>
    struct is_iterator_value_of;

    template <typename T1, typename T2>
    struct is_convertible_to_cref_of;

    template <typename F, typename ...Args>
    struct is_invocable;

    template <typename F, typename ...Args>
    struct invoke_result;

    template <typename T, typename F, typename ...Args>
    struct is_invoke_result_of;

    template <typename T>
    struct is_boolean_expression;
}}  // namespace odds_and_ends::static_introspection

namespace odds_and_ends { namespace static_introspection { namespace nested_template {

    template <typename T>
    struct has_apply;

    template <typename T>
    struct has_rebind;
}}}  // namespace odds_and_ends::static_introspection::nested_template

namespace odds_and_ends { namespace static_introspection { namespace nested_type {

    template <typename T>
    struct has_self;

    template <typename T>
    struct self_of;

    template <typename T>
    using self_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::self_of<T>::type;

    template <typename T1, typename T2>
    struct is_self_of;

    template <typename T>
    struct has_tag;

    template <typename T>
    struct tag_of;

    template <typename T>
    using tag_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::tag_of<T>::type;

    template <typename T1, typename T2>
    struct is_tag_of;

    template <typename T>
    struct has_type;

    template <typename T>
    struct type_of;

    template <typename T>
    using type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::type_of<T>::type;

    template <typename T1, typename T2>
    struct is_type_of;

    template <typename T>
    struct has_const_type;

    template <typename T>
    struct const_type_of;

    template <typename T>
    using const_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::const_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_const_type_of;

    template <typename T>
    struct has_result_type;

    template <typename T>
    struct has_backend_type;

    template <typename T>
    struct backend_type_of;

    template <typename T>
    using backend_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::backend_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_backend_type_of;

    template <typename T>
    struct has_element_type;

    template <typename T>
    struct element_type_of;

    template <typename T>
    using element_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::element_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_element_type_of;

    template <typename T>
    struct has_pointer_element_type;

    template <typename T>
    struct pointer_element_type_of;

    template <typename T>
    using pointer_element_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::pointer_element_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_pointer_element_type_of;

    template <typename T>
    struct has_param_type;

    template <typename T>
    struct param_type_of;

    template <typename T>
    using param_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::param_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_param_type_of;

    template <typename T>
    struct has_distribution_type;

    template <typename T>
    struct distribution_type_of;

    template <typename T>
    using distribution_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::distribution_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_distribution_type_of;

    template <typename T>
    struct has_policy_type;

    template <typename T>
    struct policy_type_of;

    template <typename T>
    using policy_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::policy_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_policy_type_of;

    template <typename T>
    struct has_first_type;

    template <typename T>
    struct first_type_of;

    template <typename T>
    using first_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::first_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_first_type_of;

    template <typename T>
    struct has_second_type;

    template <typename T>
    struct second_type_of;

    template <typename T>
    using second_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::second_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_second_type_of;

    template <typename T>
    struct has_first_param_type;

    template <typename T>
    struct first_param_type_of;

    template <typename T>
    using first_param_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::first_param_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_first_param_type_of;

    template <typename T>
    struct has_second_param_type;

    template <typename T>
    struct second_param_type_of;

    template <typename T>
    using second_param_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::second_param_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_second_param_type_of;

    template <typename T>
    struct has_first_reference;

    template <typename T>
    struct first_reference_of;

    template <typename T>
    using first_reference_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::first_reference_of<T>::type;

    template <typename T1, typename T2>
    struct is_first_reference_of;

    template <typename T>
    struct has_second_reference;

    template <typename T>
    struct second_reference_of;

    template <typename T>
    using second_reference_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::second_reference_of<T>::type;

    template <typename T1, typename T2>
    struct is_second_reference_of;

    template <typename T>
    struct has_int_type;

    template <typename T>
    struct int_type_of;

    template <typename T>
    using int_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::int_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_int_type_of;

    template <typename T>
    struct has_value_type;

    template <typename T>
    struct value_type_of;

    template <typename T>
    using value_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::value_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_value_type_of;

    template <typename T>
    struct has_reference;

    template <typename T>
    struct reference_of;

    template <typename T>
    using reference_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::reference_of<T>::type;

    template <typename T1, typename T2>
    struct is_reference_of;

    template <typename T>
    struct has_pointer;

    template <typename T>
    struct has_void_pointer;

    template <typename T>
    struct has_iterator_category;

    template <typename T>
    struct has_container_type;

    template <typename T>
    struct container_type_of;

    template <typename T>
    using container_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::container_type_of<T>::type;

    template <typename T>
    struct has_char_type;

    template <typename T>
    struct char_type_of;

    template <typename T>
    using char_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::char_type_of<T>::type;

    template <typename T>
    struct has_other;

    template <typename T>
    struct other_of;

    template <typename T>
    using other_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::other_of<T>::type;

    template <typename T>
    struct has_iterator;

    template <typename T>
    struct iterator_of;

    template <typename T>
    using iterator_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::iterator_of<T>::type;

    template <typename T1, typename T2>
    struct is_iterator_of;

    template <typename T>
    struct has_iterator1;

    template <typename T>
    struct iterator1_of;

    template <typename T>
    using iterator1_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::iterator1_of<T>::type;

    template <typename T1, typename T2>
    struct is_iterator1_of;

    template <typename T>
    struct has_iterator2;

    template <typename T>
    struct iterator2_of;

    template <typename T>
    using iterator2_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::iterator2_of<T>::type;

    template <typename T1, typename T2>
    struct is_iterator2_of;

    template <typename T>
    struct has_array_range;

    template <typename T>
    struct array_range_of;

    template <typename T>
    using array_range_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::array_range_of<T>::type;

    template <typename T>
    struct has_capacity_type;

    template <typename T>
    struct capacity_type_of;

    template <typename T>
    using capacity_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::capacity_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_capacity_type_of;

    template <typename T>
    struct has_size_type;

    template <typename T>
    struct size_type_of;

    template <typename T>
    using size_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::size_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_size_type_of;

    template <typename T>
    struct has_allocator_type;

    template <typename T>
    struct allocator_type_of;

    template <typename T>
    using allocator_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::allocator_type_of<T>::type;

    template <typename T>
    struct has_object_type;

    template <typename T>
    struct object_type_of;

    template <typename T>
    using object_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::object_type_of<T>::type;

    template <typename T>
    struct has_auto_type;

    template <typename T>
    struct auto_type_of;

    template <typename T>
    using auto_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::auto_type_of<T>::type;

    template <typename T>
    struct has_key_type;

    template <typename T>
    struct key_type_of;

    template <typename T>
    using key_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::key_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_key_type_of;

    template <typename T>
    struct has_mapped_type;

    template <typename T>
    struct mapped_type_of;

    template <typename T>
    using mapped_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::mapped_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_mapped_type_of;

    template <typename T>
    struct has_hasher;

    template <typename T>
    struct hasher_of;

    template <typename T>
    using hasher_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::hasher_of<T>::type;

    template <typename T1, typename T2>
    struct is_hasher_of;

    template <typename T>
    struct has_key_equal;

    template <typename T>
    struct key_equal_of;

    template <typename T>
    using key_equal_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::key_equal_of<T>::type;

    template <typename T1, typename T2>
    struct is_key_equal_of;

    template <typename T>
    struct has_key_compare;

    template <typename T>
    struct key_compare_of;

    template <typename T>
    using key_compare_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::key_compare_of<T>::type;

    template <typename T1, typename T2>
    struct is_key_compare_of;

    template <typename T>
    struct has_value_compare;

    template <typename T>
    struct value_compare_of;

    template <typename T>
    using value_compare_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::value_compare_of<T>::type;

    template <typename T1, typename T2>
    struct is_value_compare_of;

    template <typename T>
    struct has_array_type;

    template <typename T>
    struct array_type_of;

    template <typename T>
    using array_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::array_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_array_type_of;

    template <typename T>
    struct has_element;

    template <typename T>
    struct element_of;

    template <typename T>
    using element_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::element_of<T>::type;

    template <typename T1, typename T2>
    struct is_element_of;

    template <typename T, typename ResultPlaceholderExpr>
    struct has_index;

    template <typename T>
    struct index_of;

    template <typename T>
    using index_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::index_of<T>::type;

    template <typename T1, typename T2>
    struct is_index_of;

    template <typename T>
    struct has_index_gen;

    template <typename T>
    struct index_gen_of;

    template <typename T>
    using index_gen_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::index_gen_of<T>::type;

    template <typename T1, typename T2>
    struct is_index_gen_of;

    template <typename T>
    struct has_index_range;

    template <typename T>
    struct index_range_of;

    template <typename T>
    using index_range_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::index_range_of<T>::type;

    template <typename T1, typename T2>
    struct is_index_range_of;

    template <typename T>
    struct has_left_map;

    template <typename T>
    struct left_map_of;

    template <typename T1, typename T2>
    struct is_left_map_of;

    template <typename T>
    using left_map_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::left_map_of<T>::type;

    template <typename T>
    struct has_right_map;

    template <typename T>
    struct right_map_of;

    template <typename T>
    using right_map_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::right_map_of<T>::type;

    template <typename T1, typename T2>
    struct is_right_map_of;

    template <typename T>
    struct has_node_type;

    template <typename T>
    struct node_type_of;

    template <typename T>
    using node_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::node_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_node_type_of;

    template <typename T>
    struct has_insert_return_type;

    template <typename T>
    struct insert_return_type_of;

    template <typename T>
    using insert_return_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::insert_return_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_insert_return_type_of;

    template <typename T>
    struct iterator_bool_pair_of;

    template <typename T>
    using iterator_bool_pair_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::iterator_bool_pair_of<T>::type;

    template <typename T1, typename T2>
    struct is_iterator_bool_pair_of;

    template <typename T>
    struct has_reverse_iterator;

    template <typename T>
    struct reverse_iterator_of;

    template <typename T>
    using reverse_iterator_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::reverse_iterator_of<T>::type;

    template <typename T1, typename T2>
    struct is_reverse_iterator_of;

    template <typename T>
    struct has_reverse_iterator1;

    template <typename T>
    struct reverse_iterator1_of;

    template <typename T>
    using reverse_iterator1_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::reverse_iterator1_of<T>::type;

    template <typename T1, typename T2>
    struct is_reverse_iterator1_of;

    template <typename T>
    struct has_reverse_iterator2;

    template <typename T>
    struct reverse_iterator2_of;

    template <typename T>
    using reverse_iterator2_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::reverse_iterator2_of<T>::type;

    template <typename T1, typename T2>
    struct is_reverse_iterator2_of;

    template <typename T>
    struct has_ordered_iterator;

    template <typename T>
    struct ordered_iterator_of;

    template <typename T>
    using ordered_iterator_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::ordered_iterator_of<T>::type;

    template <typename T1, typename T2>
    struct is_ordered_iterator_of;

    template <typename T>
    struct has_local_iterator;

    template <typename T>
    struct local_iterator_of;

    template <typename T>
    using local_iterator_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::local_iterator_of<T>::type;

    template <typename T1, typename T2>
    struct is_local_iterator_of;

    template <typename T>
    struct has_handle_type;

    template <typename T>
    struct handle_type_of;

    template <typename T>
    using handle_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::handle_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_handle_type_of;

    template <typename T>
    struct has_expression_type;

    template <typename T>
    struct expression_type_of;

    template <typename T>
    using expression_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::expression_type_of<T>::type;

    template <typename T1, typename T2>
    struct is_expression_type_of;

    template <typename T>
    struct allocator_pointer_of;

    template <typename T>
    using allocator_pointer_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::allocator_pointer_of<T>::type;

    template <typename T1, typename T2>
    struct is_allocator_pointer_of;

    template <typename T>
    struct allocator_difference_of;

    template <typename T>
    using allocator_difference_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::allocator_difference_of<T>::type;

    template <typename T>
    struct allocator_size_of;

    template <typename T>
    using allocator_size_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::allocator_size_of<T>::type;

    template <typename T>
    struct has_type_category;

    template <typename T>
    struct type_category_of;

    template <typename T>
    using type_category_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::type_category_of<T>::type;

    template <typename T1, typename T2>
    struct is_type_category_of;

    template <typename T>
    struct has_is_view;

    template <typename T>
    struct has_category;

    template <typename T>
    struct category_of;

    template <typename T>
    using category_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::category_of<T>::type;

    template <typename T1, typename T2>
    struct is_category_of;

    template <typename T>
    struct has_vertex_descriptor;

    template <typename T>
    struct vertex_descriptor_of;

    template <typename T>
    using vertex_descriptor_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::vertex_descriptor_of<T>::type;

    template <typename T1, typename T2>
    struct is_vertex_descriptor_of;

    template <typename T>
    struct has_edge_descriptor;

    template <typename T>
    struct edge_descriptor_of;

    template <typename T>
    using edge_descriptor_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::edge_descriptor_of<T>::type;

    template <typename T1, typename T2>
    struct is_edge_descriptor_of;

    template <typename T>
    struct has_vertices_size_type;

    template <typename T>
    struct vertices_size_type_of;

    template <typename T>
    using vertices_size_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::vertices_size_type_of<T>::type;

    template <typename T>
    struct has_edges_size_type;

    template <typename T>
    struct edges_size_type_of;

    template <typename T>
    using edges_size_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::edges_size_type_of<T>::type;

    template <typename T>
    struct has_degree_size_type;

    template <typename T>
    struct degree_size_type_of;

    template <typename T>
    using degree_size_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::degree_size_type_of<T>::type;

    template <typename T>
    struct has_vertex_property_type;

    template <typename T>
    struct vertex_property_type_of;

    template <typename T>
    using vertex_property_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::vertex_property_type_of<T>::type;

    template <typename T>
    struct has_edge_property_type;

    template <typename T>
    struct edge_property_type_of;

    template <typename T>
    using edge_property_type_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::edge_property_type_of<T>::type;

    template <typename T>
    struct has_vertex_iterator;

    template <typename T>
    struct vertex_iterator_of;

    template <typename T>
    using vertex_iterator_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::vertex_iterator_of<T>::type;

    template <typename T>
    struct has_edge_iterator;

    template <typename T>
    struct edge_iterator_of;

    template <typename T>
    using edge_iterator_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::edge_iterator_of<T>::type;

    template <typename T>
    struct has_out_edge_iterator;

    template <typename T>
    struct out_edge_iterator_of;

    template <typename T>
    using out_edge_iterator_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::out_edge_iterator_of<T>::type;

    template <typename T>
    struct has_in_edge_iterator;

    template <typename T>
    struct in_edge_iterator_of;

    template <typename T>
    using in_edge_iterator_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::in_edge_iterator_of<T>::type;

    template <typename T>
    struct has_adjacency_iterator;

    template <typename T>
    struct adjacency_iterator_of;

    template <typename T>
    using adjacency_iterator_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::adjacency_iterator_of<T>::type;

    template <typename T>
    struct has_traversal_category;

    template <typename T>
    struct traversal_category_of;

    template <typename T>
    using traversal_category_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::traversal_category_of<T>::type;

    template <typename T>
    struct has_directed_category;

    template <typename T>
    struct directed_category_of;

    template <typename T>
    using directed_category_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::directed_category_of<T>::type;

    template <typename T>
    struct has_edge_parallel_category;

    template <typename T>
    struct edge_parallel_category_of;

    template <typename T>
    using edge_parallel_category_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::edge_parallel_category_of<T>::type;

    template <typename T>
    struct has_event_filter;

    template <typename T>
    struct event_filter_of;

    template <typename T>
    using event_filter_of_t = typename ::odds_and_ends
    ::static_introspection::nested_type::event_filter_of<T>::type;

    template <typename T1, typename T2>
    struct is_event_filter_of;

    template <typename T>
    struct has_next;

    template <typename T>
    struct next_to;

    template <typename T>
    using next_to_t = typename ::odds_and_ends
    ::static_introspection::nested_type::next_to<T>::type;

    template <typename T1, typename T2>
    struct is_next_to;

    template <typename T>
    struct has_prior;

    template <typename T>
    struct prior_to;

    template <typename T>
    using prior_to_t = typename ::odds_and_ends
    ::static_introspection::nested_type::prior_to<T>::type;

    template <typename T1, typename T2>
    struct is_prior_to;

    template <typename T>
    struct has_impl;

    template <typename T>
    struct has_dependencies;

    template <typename T>
    struct has_is_weight_accumulator;
}}}  // namespace odds_and_ends::static_introspection::nested_type

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename ResultPlaceholderExpr, typename ResultIfNoBase>
    struct has_base;

    template <typename T>
    struct has_clear;

    template <typename T>
    struct has_pop;

    template <typename T>
    struct has_pop_back;

    template <typename T>
    struct has_pop_front;

    template <typename T>
    struct has_swap;

    template <typename T>
    struct has_merge;

    template <typename T>
    struct has_deallocate;

    template <typename T, typename U>
    struct has_deallocate_clone;

    template <typename T, typename... Args>
    struct has_reset;

    template <typename T, typename... Args>
    struct has_emplace;

    template <typename T, typename... Args>
    struct has_emplace_back;

    template <typename T, typename... Args>
    struct has_emplace_front;

    template <typename T, typename... Args>
    struct has_emplace_after;
}}}  // namespace odds_and_ends::static_introspection::member_function

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_incrementable;

    template <typename T>
    struct is_decrementable;

    template <typename T>
    struct is_boolean_expression;

    template <typename T>
    struct is_bitmask_type;

    template <typename T>
    struct is_math_distribution;

    template <typename T>
    struct is_std_integral_constant;

    template <typename T>
    struct is_std_boolean_constant;

    template <typename T>
    struct is_mpl_static_constant;

    template <typename T>
    struct is_mpl_boolean_constant;

    template <typename T>
    struct is_mpl_integral_constant;

    template <typename T>
    struct is_rational_constant;

    template <typename T>
    struct is_accumulator;

    template <typename T>
    struct is_accumulator_feature;

    template <typename T>
    struct is_optional_pointee;

    template <typename T>
    struct is_nullable_pointer;

    template <typename T>
    struct is_readable_iterator;

    template <typename T, typename Value>
    struct is_writable_iterator_ext;

    template <typename T>
    struct is_lvalue_iterator;

    template <typename T>
    struct is_incrementable_iterator_ext;

    template <typename T>
    struct is_incrementable_iterator;

    template <typename T>
    struct is_single_pass_iterator;

    template <typename T>
    struct is_forward_traversal_iterator;

    template <typename T>
    struct is_bidirectional_traversal_iterator;

    template <typename T, typename IsStrict>
    struct is_indexable_iterator_ext;

    template <typename T>
    struct is_random_access_traversal_iterator;

    template <typename T>
    struct is_legacy_iterator;

    template <typename T>
    struct is_legacy_input_iterator;

    template <typename T>
    struct is_legacy_forward_iterator;

    template <typename T>
    struct is_legacy_bidirectional_iterator;

    template <typename T>
    struct is_legacy_random_access_iterator;

    template <typename T>
    struct is_ptr_map_iterator;

    template <typename T>
    struct is_allocator;

    template <typename T, typename U>
    struct is_clone_allocator;

    template <typename T>
    struct is_set_node_handle;

    template <typename T>
    struct is_map_node_handle;

    template <typename T>
    struct is_array_range;

    template <typename T>
    struct is_single_pass_range;

    template <typename T>
    struct is_forward_range;

    template <typename T>
    struct is_bidirectional_range;

    template <typename T>
    struct is_indexable_range;

    template <typename T>
    struct is_random_access_range;

    template <typename T>
    struct is_indexable_container;

    template <typename T>
    struct maybe_contiguous_container;

    template <typename T>
    struct is_multi_array_index_range;

    template <typename T>
    struct is_multi_array;

    template <typename T>
    struct is_legacy_associative_container;

    template <typename T>
    struct is_legacy_unordered_associative_container;

    template <typename T>
    struct is_legacy_hashed_associative_container;

    template <typename T>
    struct is_legacy_sorted_associative_container;

    template <typename T>
    struct is_legacy_flat_associative_container;

    template <typename T>
    struct is_legacy_pair_associative_container;

    template <typename T>
    struct is_legacy_unique_associative_container;

    template <typename T>
    struct is_legacy_multiple_associative_container;

    template <typename T>
    struct is_pointer_container;

    template <typename T>
    struct is_ublas_storage;

    template <typename T>
    struct is_ublas_vector_expression;

    template <typename T>
    struct is_ublas_vector;

    template <typename T>
    struct is_ublas_matrix_minimal_expression;

    template <typename T>
    struct is_ublas_matrix_expression;

    template <typename T>
    struct is_sequence;

    template <typename T>
    struct is_back_insertion_sequence;

    template <typename T>
    struct is_front_insertion_sequence;

    template <typename T>
    struct is_circular_buffer;

    template <typename T>
    struct is_queue;

    template <typename T>
    struct is_stack_or_std_heap;

    template <typename T>
    struct is_boost_heap;

    template <typename T>
    struct is_iteratable_heap;

    template <typename T>
    struct is_order_iteratable_heap;

    template <typename T>
    struct is_mergeable_heap;

    template <typename T>
    struct is_mutable_heap;

    template <typename T>
    struct is_compressed_pair;

    template <typename T>
    struct is_half_runtime_pair;

    template <typename T>
    struct is_mpl_forward_iterator;

    template <typename T>
    struct is_mpl_bidirectional_iterator;

    template <typename T>
    struct is_mpl_random_access_iterator;

    template <typename T>
    struct is_fusion_random_access_iterator;

    template <typename T>
    struct is_fusion_associative_iterator;

    template <typename T>
    struct is_mpl_extensible_sequence;

    template <typename T>
    struct is_mpl_front_extensible_sequence;

    template <typename T>
    struct is_mpl_back_extensible_sequence;

    template <typename T>
    struct is_fusion_forward_sequence;

    template <typename T>
    struct is_fusion_bidirectional_sequence;

    template <typename T>
    struct is_fusion_random_access_sequence;

    template <typename T>
    struct is_fusion_associative_sequence;

    template <typename T>
    struct is_boost_graph;

    template <typename T>
    struct is_vertex_list_graph;

    template <typename T>
    struct is_incidence_graph;

    template <typename T>
    struct is_edge_list_graph;

    template <typename T>
    struct is_bidirectional_graph;

    template <typename T>
    struct is_adjacency_graph;

    template <typename T>
    struct is_vertex_mutable_graph;

    template <typename T>
    struct is_edge_mutable_graph;
}}}  // namespace odds_and_ends::static_introspection::concept

#include <odds_and_ends/static_introspection/remove_vref.hpp>
#include <type_traits>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <
        typename T,
        typename Difference = typename ::std::add_const<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type
        >::type
    >
    struct is_additive;

    template <
        typename T,
        typename Dividend = typename ::std::add_const<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type
        >::type
    >
    struct is_multiplicative;
}}}  // namespace odds_and_ends::static_introspection::concept

#include <boost/mpl/quote.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <
        typename T1,
        typename T2,
        typename BinaryPlaceholderExpr = ::boost::mpl::quote2< ::std::is_same>
    >
    struct is_lvalue_reference_of;

    template <
        typename T1,
        typename T2,
        typename BinaryPlaceholderExpr = ::boost::mpl::quote2< ::std::is_same>
    >
    struct is_raw_pointer_of;
}}  // namespace odds_and_ends::static_introspection

#include <boost/mpl/placeholders.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <
        typename F,
        typename ClassTransform = ::std::add_lvalue_reference< ::boost::mpl::_>
    >
    struct function_parameter_types;
}}  // namespace odds_and_ends::static_introspection

namespace odds_and_ends { namespace static_introspection { namespace member_data {

    template <
        typename T,
        typename PlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_value_type_of< ::boost::mpl::_,T>
    >
    struct has_value;
}}}  // namespace odds_and_ends::static_introspection::member_data

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <
        typename T,
        typename U,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::is_raw_pointer_of< ::boost::mpl::_,U>
    >
    struct has_allocate_clone;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::concept::is_boolean_expression< ::boost::mpl::_>
    >
    struct has_empty;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::concept::is_boolean_expression< ::boost::mpl::_>
    >
    struct has_full;

    template <
        typename T,
        typename ResultPlaceholderExpr = ::odds_and_ends
        ::static_introspection::is_allocator_pointer_of< ::boost::mpl::_,T>
    >
    struct has_data;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_int_type_of< ::boost::mpl::_,T>
    >
    struct has_numerator;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_int_type_of< ::boost::mpl::_,T>
    >
    struct has_denominator;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_int_type_of< ::boost::mpl::_,T>
    >
    struct has_integral_part;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_int_type_of< ::boost::mpl::_,T>
    >
    struct has_fractional_part;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_param_type_of< ::boost::mpl::_,T>
    >
    struct has_param;

    template <
        typename T,
        typename Index,
        typename ResultPlaceholderExpr = ::odds_and_ends
        ::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct has_at;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_iterator_of< ::boost::mpl::_,T>
    >
    struct has_begin;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_iterator_of< ::boost::mpl::_,T>
    >
    struct has_end;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_iterator1_of< ::boost::mpl::_,T>
    >
    struct has_begin1;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_iterator1_of< ::boost::mpl::_,T>
    >
    struct has_end1;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_iterator2_of< ::boost::mpl::_,T>
    >
    struct has_begin2;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_iterator2_of< ::boost::mpl::_,T>
    >
    struct has_end2;

    template <
        typename T,
        typename ResultPlaceholderExpr = ::odds_and_ends::static_introspection
        ::nested_type::is_reverse_iterator_of< ::boost::mpl::_,T>
    >
    struct has_rbegin;

    template <
        typename T,
        typename ResultPlaceholderExpr = ::odds_and_ends::static_introspection
        ::nested_type::is_reverse_iterator_of< ::boost::mpl::_,T>
    >
    struct has_rend;

    template <
        typename T,
        typename ResultPlaceholderExpr = ::odds_and_ends::static_introspection
        ::nested_type::is_reverse_iterator1_of< ::boost::mpl::_,T>
    >
    struct has_rbegin1;

    template <
        typename T,
        typename ResultPlaceholderExpr = ::odds_and_ends::static_introspection
        ::nested_type::is_reverse_iterator1_of< ::boost::mpl::_,T>
    >
    struct has_rend1;

    template <
        typename T,
        typename ResultPlaceholderExpr = ::odds_and_ends::static_introspection
        ::nested_type::is_reverse_iterator2_of< ::boost::mpl::_,T>
    >
    struct has_rbegin2;

    template <
        typename T,
        typename ResultPlaceholderExpr = ::odds_and_ends::static_introspection
        ::nested_type::is_reverse_iterator2_of< ::boost::mpl::_,T>
    >
    struct has_rend2;

    template <
        typename T,
        typename ResultPlaceholderExpr = ::odds_and_ends::static_introspection
        ::nested_type::is_ordered_iterator_of< ::boost::mpl::_,T>
    >
    struct has_ordered_begin;

    template <
        typename T,
        typename ResultPlaceholderExpr = ::odds_and_ends::static_introspection
        ::nested_type::is_ordered_iterator_of< ::boost::mpl::_,T>
    >
    struct has_ordered_end;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_reference_of< ::boost::mpl::_,T>
    >
    struct has_front;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_reference_of< ::boost::mpl::_,T>
    >
    struct has_back;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_reference_of< ::boost::mpl::_,T>
    >
    struct has_top;

    template <
        typename T,
        typename ResultPlaceholderExpr = ::odds_and_ends::static_introspection
        ::nested_type::is_capacity_type_of< ::boost::mpl::_,T>
    >
    struct has_capacity;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_size_type_of< ::boost::mpl::_,T>
    >
    struct has_max_size;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_size_type_of< ::boost::mpl::_,T>
    >
    struct has_size1;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_size_type_of< ::boost::mpl::_,T>
    >
    struct has_size2;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_size_type_of< ::boost::mpl::_,T>
    >
    struct has_num_dimensions;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_size_type_of< ::boost::mpl::_,T>
    >
    struct has_num_elements;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_size_type_of< ::boost::mpl::_,T>
    >
    struct has_max_bucket_count;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_size_type_of< ::boost::mpl::_,T>
    >
    struct has_bucket_count;
}}}  // namespace odds_and_ends::static_introspection::member_function

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <
        typename T,
        typename ResultPlaceholderExpr = 
        ::odds_and_ends::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct is_pre_incrementable;

    template <
        typename T,
        typename ResultPlaceholderExpr = 
        ::odds_and_ends::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct is_pre_decrementable;

    template <
        typename T,
        typename Subscript,
        typename ResultPlaceholderExpr = ::odds_and_ends
        ::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct is_subscriptable;

    template <
        typename T,
        typename FirstPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_first_type_of< ::boost::mpl::_,T>,
        typename SecondPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_second_type_of< ::boost::mpl::_,T>
    >
    struct is_runtime_pair;

    template <
        typename T,
        typename PlaceholderExpr = ::odds_and_ends::static_introspection
        ::concept::is_legacy_bidirectional_iterator< ::boost::mpl::_>
    >
    struct is_reversible;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::concept::is_mpl_forward_iterator< ::boost::mpl::_>
    >
    struct is_mpl_sequence;

    template <
        typename T,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::concept::is_mpl_forward_iterator< ::boost::mpl::_>
    >
    struct is_mpl_associative_sequence;

    template <
        typename T,
        typename ResultPlaceholderExpr = ::odds_and_ends
        ::static_introspection::is_convertible_to_cref_of< ::boost::mpl::_,T>
    >
    struct is_complementable;

    template <
        typename T,
        typename ResultPlaceholderExpr = ::odds_and_ends
        ::static_introspection::is_convertible_to_cref_of< ::boost::mpl::_,T>
    >
    struct is_identity_operable;

    template <
        typename T,
        typename ResultPlaceholderExpr = ::odds_and_ends
        ::static_introspection::is_convertible_to_cref_of< ::boost::mpl::_,T>
    >
    struct is_negatable;

    template <
        typename T,
        typename PlaceholderExpr = ::odds_and_ends
        ::static_introspection::is_convertible_to_cref_of< ::boost::mpl::_,T>
    >
    struct is_math_real_type;

    template <
        typename T,
        typename PlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_int_type_of< ::boost::mpl::_,T>
    >
    struct is_math_rational_type;

    template <
        typename T,
        typename PlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_int_type_of< ::boost::mpl::_,T>
    >
    struct is_math_mixed_numeric_type;
}}}  // namespace odds_and_ends::static_introspection::concept

#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_iterator_difference;
}}  // namespace odds_and_ends::static_introspection

namespace odds_and_ends { namespace static_introspection { namespace member_data {

    template <typename T, typename PlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_num;

    template <typename T, typename PlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_den;

    template <typename T, typename PlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_left;

    template <typename T, typename PlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_right;

    template <
        typename T,
        typename PlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_first_type_of< ::boost::mpl::_,T>
    >
    struct has_first;

    template <
        typename T,
        typename PlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_second_type_of< ::boost::mpl::_,T>
    >
    struct has_second;

    template <
        typename T,
        typename PlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_size_type_of< ::boost::mpl::_,T>
    >
    struct has_max_size_static_const;

    template <
        typename T,
        typename PlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_size_type_of< ::boost::mpl::_,T>
    >
    struct has_dimensionality_static_const;
}}}  // namespace odds_and_ends::static_introspection::member_data

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_static_min;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_static_max;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_cbegin;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_cend;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_crbegin;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_crend;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_compressed_pair_first;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_compressed_pair_second;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_get_allocator;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_value;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_key;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_mapped;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_hash_function;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_key_eq;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_key_comp;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_value_comp;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_origin;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_shape;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_strides;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_index_bases;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy
    >
    struct has_start;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy
    >
    struct has_finish;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy
    >
    struct has_stride;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy
    >
    struct has_equal_range;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy
    >
    struct has_cbegin_bucket;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy
    >
    struct has_cend_bucket;

    template <typename T, typename U = ::odds_and_ends::use_default_policy>
    struct has_real;

    template <typename T, typename U = ::odds_and_ends::use_default_policy>
    struct has_imag;

    template <typename T, typename U = ::odds_and_ends::use_default_policy>
    struct has_reserve;

    template <typename T, typename Param = ::odds_and_ends::use_default_policy>
    struct has_rehash;

    template <typename T, typename Param = ::odds_and_ends::use_default_policy>
    struct has_push;

    template <typename T, typename Param = ::odds_and_ends::use_default_policy>
    struct has_push_back;

    template <typename T, typename Param = ::odds_and_ends::use_default_policy>
    struct has_push_front;

    template <typename T, typename Param1, typename Param2 = ::odds_and_ends::use_default_policy>
    struct has_update;

    template <typename T, typename Param1, typename Param2 = ::odds_and_ends::use_default_policy>
    struct has_increase;

    template <typename T, typename Param1, typename Param2 = ::odds_and_ends::use_default_policy>
    struct has_decrease;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct has_null_vertex;

    template <
        typename T,
        typename Value = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::is_convertible_to_cref_of< ::boost::mpl::_,T>
    >
    struct has_assign;

    template <
        typename T,
        typename Addend = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct has_plus_assign;

    template <
        typename T,
        typename Difference = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct has_minus_assign;

    template <
        typename T,
        typename U = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends::static_introspection
        ::nested_type::is_allocator_pointer_of< ::boost::mpl::_,T>
    >
    struct has_allocate;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_iterator_of< ::boost::mpl::_,T>
    >
    struct has_find;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_iterator_of< ::boost::mpl::_,T>
    >
    struct has_lower_bound;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_iterator_of< ::boost::mpl::_,T>
    >
    struct has_upper_bound;

    template <
        typename T,
        typename Param1,
        typename Param2 = ::odds_and_ends::use_default_policy,
        typename Param3 = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_iterator_of< ::boost::mpl::_,T>
    >
    struct has_insert;

    template <
        typename T,
        typename Param1,
        typename Param2 = ::odds_and_ends::use_default_policy,
        typename Param3 = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_iterator_of< ::boost::mpl::_,T>
    >
    struct has_insert_after;

    template <
        typename T,
        typename Param1,
        typename Param2 = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_iterator_of< ::boost::mpl::_,T>
    >
    struct has_erase;

    template <
        typename T,
        typename Param1,
        typename Param2 = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_iterator_of< ::boost::mpl::_,T>
    >
    struct has_erase_after;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_size_type_of< ::boost::mpl::_,T>
    >
    struct has_size;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_size_type_of< ::boost::mpl::_,T>
    >
    struct has_bucket_size;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_size_type_of< ::boost::mpl::_,T>
    >
    struct has_bucket;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_size_type_of< ::boost::mpl::_,T>
    >
    struct has_count;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends::static_introspection
        ::nested_type::is_local_iterator_of< ::boost::mpl::_,T>
    >
    struct has_begin_bucket;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends::static_introspection
        ::nested_type::is_local_iterator_of< ::boost::mpl::_,T>
    >
    struct has_end_bucket;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_node_type_of< ::boost::mpl::_,T>
    >
    struct has_extract;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_index_of< ::boost::mpl::_,T>
    >
    struct has_get_start;

    template <
        typename T,
        typename Param = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::nested_type::is_index_of< ::boost::mpl::_,T>
    >
    struct has_get_finish;
}}}  // namespace odds_and_ends::static_introspection::member_function

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename U = ::odds_and_ends::use_default_policy>
    struct is_equality_comparable;

    template <typename T, typename U = ::odds_and_ends::use_default_policy>
    struct is_less_than_comparable;

    template <typename T, typename U = ::odds_and_ends::use_default_policy>
    struct is_comparable;

    template <
        typename T,
        typename Addend = T,
        typename Sum = ::odds_and_ends::use_default_policy
    >
    struct is_addable;

    template <
        typename T,
        typename Subtrahend = T,
        typename Difference = ::odds_and_ends::use_default_policy
    >
    struct is_subtractable;

    template <
        typename T,
        typename Factor = T,
        typename Product = ::odds_and_ends::use_default_policy
    >
    struct is_multipliable;

    template <
        typename T,
        typename Divisor = T,
        typename Quotient = ::odds_and_ends::use_default_policy
    >
    struct is_dividable;

    template <
        typename T,
        typename Divisor = T,
        typename Remainder = ::odds_and_ends::use_default_policy
    >
    struct is_modulus_operable;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct is_value_generator;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct is_value_distribution;

    template <typename T, typename ResultPlaceholderExpr = ::odds_and_ends::use_default_policy>
    struct is_value_distribution_with_param;

    template <typename T, typename Value = ::odds_and_ends::use_default_policy>
    struct is_writable_iterator;

    template <typename T, typename Value = ::odds_and_ends::use_default_policy>
    struct is_output_iterator;

    template <
        typename T,
        typename LeftPlaceholderExpr = ::odds_and_ends::use_default_policy,
        typename RightPlaceholderExpr = ::odds_and_ends::use_default_policy
    >
    struct is_bimap;

    template <typename T, typename Key = ::odds_and_ends::use_default_policy>
    struct is_readable_property_map;

    template <typename T, typename Key = ::odds_and_ends::use_default_policy>
    struct is_writable_property_map;

    template <typename T, typename Key = ::odds_and_ends::use_default_policy>
    struct is_read_write_property_map;

    template <typename T, typename Key = ::odds_and_ends::use_default_policy>
    struct is_lvalue_property_map;

    template <
        typename T,
        typename Value = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends
        ::static_introspection::is_convertible_to_cref_of< ::boost::mpl::_,T>
    >
    struct is_lvalue_assignable;

    template <
        typename T,
        typename Value = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends
        ::static_introspection::is_convertible_to_cref_of< ::boost::mpl::_,T>
    >
    struct is_rvalue_assignable;

    template <
        typename T,
        typename Addend = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct is_addition_assignable;

    template <
        typename T,
        typename Difference = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct is_subtraction_assignable;

    template <
        typename T,
        typename Factor = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct is_multiplication_assignable;

    template <
        typename T,
        typename Dividend = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct is_division_assignable;

    template <
        typename T,
        typename Dividend = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct is_modulus_assignable;

    template <
        typename T,
        typename Operand = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct is_bitwise_and_assignable;

    template <
        typename T,
        typename Operand = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct is_bitwise_or_assignable;

    template <
        typename T,
        typename Operand = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct is_bitwise_xor_assignable;

    template <
        typename T,
        typename Operand = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct is_left_shift_assignable;

    template <
        typename T,
        typename Operand = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr =
        ::odds_and_ends::static_introspection::is_lvalue_reference_of< ::boost::mpl::_,T>
    >
    struct is_right_shift_assignable;

    template <
        typename T,
        typename Operand = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends
        ::static_introspection::is_convertible_to_cref_of< ::boost::mpl::_,T>
    >
    struct is_bitwise_and_operable;

    template <
        typename T,
        typename Operand = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends
        ::static_introspection::is_convertible_to_cref_of< ::boost::mpl::_,T>
    >
    struct is_bitwise_or_operable;

    template <
        typename T,
        typename Operand = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends
        ::static_introspection::is_convertible_to_cref_of< ::boost::mpl::_,T>
    >
    struct is_bitwise_xor_operable;

    template <
        typename T,
        typename Operand = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends
        ::static_introspection::is_convertible_to_cref_of< ::boost::mpl::_,T>
    >
    struct is_left_shift_operable;

    template <
        typename T,
        typename Operand = ::odds_and_ends::use_default_policy,
        typename ResultPlaceholderExpr = ::odds_and_ends
        ::static_introspection::is_convertible_to_cref_of< ::boost::mpl::_,T>
    >
    struct is_right_shift_operable;
}}}  // namespace odds_and_ends::static_introspection::concept

#include <boost/mpl/bool.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename IsStrict = ::boost::mpl::false_>
    struct is_indexable_iterator;

    template <typename T, typename IsStrict = ::boost::mpl::false_>
    struct is_indexable_traversal_iterator;

    template <typename T, typename IsStrict = ::boost::mpl::false_>
    struct is_container;

    template <typename T, typename IsStrict = ::boost::mpl::false_>
    struct is_reversible_container;

    template <typename T, typename IsStrict = ::boost::mpl::false_>
    struct is_allocator_aware;

    template <typename T, typename IsStrict = ::boost::mpl::false_>
    struct is_ublas_matrix;

    template <typename T, typename IsStrict = ::boost::mpl::false_>
    struct is_math_complex_type;
}}}  // namespace odds_and_ends::static_introspection::concept

#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <
        typename T,
        typename ResultPlaceholderExpr = ::boost::mpl::if_<
            ::std::is_convertible< ::boost::mpl::_,bool>,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >
    >
    struct is_logically_negatable;
}}}  // namespace odds_and_ends::static_introspection::concept

#include <boost/mpl/always.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <
        typename T,
        typename Param,
        typename ResultPlaceholderExpr = ::boost::mpl::always< ::boost::mpl::true_>
    >
    struct is_unary_metafunction_class;

    template <
        typename T,
        typename Param1,
        typename Param2,
        typename ResultPlaceholderExpr = ::boost::mpl::always< ::boost::mpl::true_>
    >
    struct is_binary_metafunction_class;
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION_FWD_HPP

