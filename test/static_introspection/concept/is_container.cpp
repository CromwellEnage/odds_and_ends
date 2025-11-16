// Copyright (C) 2025 Cromwell D. Enage

#include <tuple>
#include <utility>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <boost/container/vector.hpp>
#include <boost/container/stable_vector.hpp>
#include <boost/container/static_vector.hpp>
#include <boost/container/small_vector.hpp>
#include <boost/container/devector.hpp>
#include <boost/container/deque.hpp>
#include <boost/container/slist.hpp>
#include <boost/container/list.hpp>
#include <boost/container/set.hpp>
#include <boost/container/flat_set.hpp>
#include <boost/unordered/unordered_set.hpp>
#include <boost/container/map.hpp>
#include <boost/container/flat_map.hpp>
#include <boost/unordered/unordered_map.hpp>
#include <boost/ptr_container/ptr_array.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_deque.hpp>
#include <boost/ptr_container/ptr_list.hpp>
#include <boost/ptr_container/ptr_set.hpp>
#include <boost/ptr_container/ptr_unordered_set.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <boost/ptr_container/ptr_unordered_map.hpp>
#include <boost/heap/priority_queue.hpp>
#include <boost/heap/d_ary_heap.hpp>
#include <boost/heap/binomial_heap.hpp>
#include <boost/heap/fibonacci_heap.hpp>
#include <boost/heap/pairing_heap.hpp>
#include <boost/heap/skew_heap.hpp>
#include <odds_and_ends/static_introspection/concept/is_runtime_pair.hpp>

void test_runtime_pair()
{
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::pair<char,short> >::value,
        "::std::pair is a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::tuple<char,short> >::value,
        "::std::tuple is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::array<int,5> >::value,
        "::std::array is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::vector<int> >::value,
        "::std::vector is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::deque<int> >::value,
        "::std::deque is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::forward_list<int> >::value,
        "::std::forward_list is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::list<int> >::value,
        "::std::list is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::set<int> >::value,
        "::std::set is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::multiset<int> >::value,
        "::std::multiset is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::unordered_set<int> >::value,
        "::std::unordered_set is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::map<int,int> >::value,
        "::std::map is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::multimap<int,int> >::value,
        "::std::multimap is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::stack<int> >::value,
        "::std::stack is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::queue<int> >::value,
        "::std::queue is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::vector<int> >::value,
        "::boost::container::vector is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::static_vector<int,10> >::value,
        "::boost::container::static_vector is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::small_vector<int,5> >::value,
        "::boost::container::small_vector is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::devector<int> >::value,
        "::boost::container::devector is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::deque<int> >::value,
        "::boost::container::deque is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::list<int> >::value,
        "::boost::container::list is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::set<int> >::value,
        "::boost::container::set is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::unordered::unordered_multiset<int> >::value,
        "::boost::unordered::unordered_multiset is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::map<int,int> >::value,
        "::boost::container::map is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::unordered::unordered_map<int,int> >::value,
        "::boost::unordered::unordered_map is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::container::flat_multimap<int,int> >::value,
        "::boost::container::flat_multimap is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::unordered::unordered_multimap<int,int> >::value,
        "::boost::unordered::unordered_multimap is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::ptr_multiset<int> >::value,
        "::boost::ptr_multiset is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> > >::value,
        "::boost::heap::d_ary_heap is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not a C++-Standard Runtime Pair."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_runtime_pair< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not a C++-Standard Runtime Pair."
    );
}

#include <odds_and_ends/static_introspection/concept/is_std_tuple.hpp>

void test_std_tuple()
{
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::pair<char,short> >::value,
        "::std::pair is a C++-Standard Tuple."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::tuple<char,short> >::value,
        "::std::tuple is a C++-Standard Tuple."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::array<int,5> >::value,
        "::std::array is a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::vector<int> >::value,
        "::std::vector is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::deque<int> >::value,
        "::std::deque is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::forward_list<int> >::value,
        "::std::forward_list is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::list<int> >::value,
        "::std::list is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::set<int> >::value,
        "::std::set is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::multiset<int> >::value,
        "::std::multiset is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::unordered_set<int> >::value,
        "::std::unordered_set is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::map<int,int> >::value,
        "::std::map is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::multimap<int,int> >::value,
        "::std::multimap is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::stack<int> >::value,
        "::std::stack is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::queue<int> >::value,
        "::std::queue is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::vector<int> >::value,
        "::boost::container::vector is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::static_vector<int,10> >::value,
        "::boost::container::static_vector is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::small_vector<int,5> >::value,
        "::boost::container::small_vector is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::devector<int> >::value,
        "::boost::container::devector is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::deque<int> >::value,
        "::boost::container::deque is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::list<int> >::value,
        "::boost::container::list is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::set<int> >::value,
        "::boost::container::set is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::unordered::unordered_multiset<int> >::value,
        "::boost::unordered::unordered_multiset is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::map<int,int> >::value,
        "::boost::container::map is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::unordered::unordered_map<int,int> >::value,
        "::boost::unordered::unordered_map is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::container::flat_multimap<int,int> >::value,
        "::boost::container::flat_multimap is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::unordered::unordered_multimap<int,int> >::value,
        "::boost::unordered::unordered_multimap is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::ptr_multiset<int> >::value,
        "::boost::ptr_multiset is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> > >::value,
        "::boost::heap::d_ary_heap is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not a C++-Standard Tuple."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not a C++-Standard Tuple."
    );
}

#include <odds_and_ends/static_introspection/concept/is_single_pass_range.hpp>

void test_single_pass_range()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::pair<char,short> >::value,
        "::std::pair<char,short> is not a Boost Single Pass Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::tuple<char,short> >::value,
        "::std::tuple is not a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::array<int,5> >::value,
        "::std::tuple is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::vector<int> >::value,
        "::std::vector is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::deque<int> >::value,
        "::std::deque is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::forward_list<int> >::value,
        "::std::forward_list is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::list<int> >::value,
        "::std::list is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::set<int> >::value,
        "::std::set is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::multiset<int> >::value,
        "::std::multiset is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::unordered_set<int> >::value,
        "::std::unordered_set is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::map<int,int> >::value,
        "::std::map is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::multimap<int,int> >::value,
        "::std::multimap is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is a Boost Single Pass Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::stack<int> >::value,
        "::std::stack is not a Boost Single Pass Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::queue<int> >::value,
        "::std::queue is not a Boost Single Pass Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::vector<int> >::value,
        "::boost::container::vector is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::static_vector<int,10> >::value,
        "::boost::container::static_vector is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::small_vector<int,5> >::value,
        "::boost::container::small_vector is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::devector<int> >::value,
        "::boost::container::devector is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::deque<int> >::value,
        "::boost::container::deque is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::slist<int> >::value,
        "::boost::container::slist is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::list<int> >::value,
        "::boost::container::list is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::set<int> >::value,
        "::boost::container::set is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::unordered::unordered_multiset<int> >::value,
        "::boost::unordered::unordered_multiset is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::map<int,int> >::value,
        "::boost::container::map is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::unordered::unordered_map<int,int> >::value,
        "::boost::unordered::unordered_map is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::container::flat_multimap<int,int> >::value,
        "::boost::container::flat_multimap is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::unordered::unordered_multimap<int,int> >::value,
        "::boost::unordered::unordered_multimap is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::ptr_multiset<int> >::value,
        "::boost::ptr_multiset is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> > >::value,
        "::boost::heap::d_ary_heap is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is a Boost Single Pass Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_single_pass_range< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is a Boost Single Pass Range."
    );
}

#include <odds_and_ends/static_introspection/concept/is_forward_range.hpp>

void test_forward_range()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::pair<char,short> >::value,
        "::std::pair<char,short> is not a Boost Forward Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::tuple<char,short> >::value,
        "::std::tuple is not a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::array<int,5> >::value,
        "::std::array is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::vector<int> >::value,
        "::std::vector is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::deque<int> >::value,
        "::std::deque is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::forward_list<int> >::value,
        "::std::forward_list is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::list<int> >::value,
        "::std::list is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::set<int> >::value,
        "::std::set is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::multiset<int> >::value,
        "::std::multiset is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::unordered_set<int> >::value,
        "::std::unordered_set is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::map<int,int> >::value,
        "::std::map is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::multimap<int,int> >::value,
        "::std::multimap is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is a Boost Forward Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::stack<int> >::value,
        "::std::stack is not a Boost Forward Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::queue<int> >::value,
        "::std::queue is not a Boost Forward Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::vector<int> >::value,
        "::boost::container::vector is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::static_vector<int,10> >::value,
        "::boost::container::static_vector is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::small_vector<int,5> >::value,
        "::boost::container::small_vector is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::devector<int> >::value,
        "::boost::container::devector is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::deque<int> >::value,
        "::boost::container::deque is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::slist<int> >::value,
        "::boost::container::slist is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::list<int> >::value,
        "::boost::container::list is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::set<int> >::value,
        "::boost::container::set is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::unordered::unordered_multiset<int> >::value,
        "::boost::unordered::unordered_multiset is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::map<int,int> >::value,
        "::boost::container::map is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::unordered::unordered_map<int,int> >::value,
        "::boost::unordered::unordered_map is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::container::flat_multimap<int,int> >::value,
        "::boost::container::flat_multimap is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::unordered::unordered_multimap<int,int> >::value,
        "::boost::unordered::unordered_multimap is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::ptr_multiset<int> >::value,
        "::boost::ptr_multiset is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> > >::value,
        "::boost::heap::d_ary_heap is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is a Boost Forward Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_forward_range< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is a Boost Forward Range."
    );
}

#include <odds_and_ends/static_introspection/concept/is_bidirectional_range.hpp>

void test_bidirectional_range()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::pair<char,short> >::value,
        "::std::pair<char,short> is not a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::tuple<char,short> >::value,
        "::std::tuple is not a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::array<int,5> >::value,
        "::std::array is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::vector<int> >::value,
        "::std::vector is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::deque<int> >::value,
        "::std::deque is a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::forward_list<int> >::value,
        "::std::forward_list is not a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::list<int> >::value,
        "::std::list is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::set<int> >::value,
        "::std::set is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::multiset<int> >::value,
        "::std::multiset is a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::unordered_set<int> >::value,
        "::std::unordered_set is not a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is not a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::map<int,int> >::value,
        "::std::map is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::multimap<int,int> >::value,
        "::std::multimap is a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is not a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is not a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::stack<int> >::value,
        "::std::stack is not a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::queue<int> >::value,
        "::std::queue is not a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::vector<int> >::value,
        "::boost::container::vector is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::static_vector<int,10> >::value,
        "::boost::container::static_vector is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::small_vector<int,5> >::value,
        "::boost::container::small_vector is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::devector<int> >::value,
        "::boost::container::devector is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::deque<int> >::value,
        "::boost::container::deque is a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::list<int> >::value,
        "::boost::container::list is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::set<int> >::value,
        "::boost::container::set is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is not a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::unordered::unordered_multiset<int> >::value,
        "::boost::unordered::unordered_multiset is not a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::map<int,int> >::value,
        "::boost::container::map is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::unordered::unordered_map<int,int> >::value,
        "::boost::unordered::unordered_map is not a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::container::flat_multimap<int,int> >::value,
        "::boost::container::flat_multimap is a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::unordered::unordered_multimap<int,int> >::value,
        "::boost::unordered::unordered_multimap is not a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is not a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::ptr_multiset<int> >::value,
        "::boost::ptr_multiset is a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is not a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is not a Boost Bidirectional Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is not a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> > >::value,
        "::boost::heap::d_ary_heap is not a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not a Boost Bidirectional Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_bidirectional_range< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not a Boost Bidirectional Range."
    );
}

#include <odds_and_ends/static_introspection/concept/is_indexable_range.hpp>

void test_indexable_range()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::pair<char,short> >::value,
        "::std::pair is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::tuple<char,short> >::value,
        "::std::tuple is not an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::array<int,5> >::value,
        "::std::array is an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::vector<int> >::value,
        "::std::vector is an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::deque<int> >::value,
        "::std::deque is an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::forward_list<int> >::value,
        "::std::forward_list is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::list<int> >::value,
        "::std::list is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::set<int> >::value,
        "::std::set is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::multiset<int> >::value,
        "::std::multiset is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::unordered_set<int> >::value,
        "::std::unordered_set is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::map<int,int> >::value,
        "::std::map is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::multimap<int,int> >::value,
        "::std::multimap is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::stack<int> >::value,
        "::std::stack is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::queue<int> >::value,
        "::std::queue is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::vector<int> >::value,
        "::boost::container::vector is an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::static_vector<int,10> >::value,
        "::boost::container::static_vector is an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::small_vector<int,5> >::value,
        "::boost::container::small_vector is an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::devector<int> >::value,
        "::boost::container::devector is an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::deque<int> >::value,
        "::boost::container::deque is an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::list<int> >::value,
        "::boost::container::list is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::set<int> >::value,
        "::boost::container::set is not an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is not an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::unordered::unordered_multiset<int> >::value,
        "::boost::unordered::unordered_multiset is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::map<int,int> >::value,
        "::boost::container::map is not an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::unordered::unordered_map<int,int> >::value,
        "::boost::unordered::unordered_map is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is not an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::container::flat_multimap<int,int> >::value,
        "::boost::container::flat_multimap is an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::unordered::unordered_multimap<int,int> >::value,
        "::boost::unordered::unordered_multimap is not an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is an Indexable Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::ptr_multiset<int> >::value,
        "::boost::ptr_multiset is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> > >::value,
        "::boost::heap::d_ary_heap is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not an Indexable Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_range< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not an Indexable Range."
    );
}

#include <odds_and_ends/static_introspection/concept/is_random_access_range.hpp>

void test_random_access_range()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::pair<char,short> >::value,
        "::std::pair<char,short> is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::tuple<char,short> >::value,
        "::std::tuple is not a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::array<int,5> >::value,
        "::std::array is a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::vector<int> >::value,
        "::std::vector is a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::deque<int> >::value,
        "::std::deque is a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::forward_list<int> >::value,
        "::std::forward_list is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::list<int> >::value,
        "::std::list is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::set<int> >::value,
        "::std::set is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::multiset<int> >::value,
        "::std::multiset is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::unordered_set<int> >::value,
        "::std::unordered_set is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::map<int,int> >::value,
        "::std::map is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::multimap<int,int> >::value,
        "::std::multimap is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::stack<int> >::value,
        "::std::stack is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::queue<int> >::value,
        "::std::queue is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::vector<int> >::value,
        "::boost::container::vector is a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::static_vector<int,10> >::value,
        "::boost::container::static_vector is a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::small_vector<int,5> >::value,
        "::boost::container::small_vector is a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::devector<int> >::value,
        "::boost::container::devector is a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::deque<int> >::value,
        "::boost::container::deque is a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::list<int> >::value,
        "::boost::container::list is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::set<int> >::value,
        "::boost::container::set is not a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is not a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::unordered::unordered_multiset<int> >::value,
        "::boost::unordered::unordered_multiset is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::map<int,int> >::value,
        "::boost::container::map is not a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_ma is a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::unordered::unordered_map<int,int> >::value,
        "::boost::unordered::unordered_map is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is not a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::container::flat_multimap<int,int> >::value,
        "::boost::container::flat_multimap is a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::unordered::unordered_multimap<int,int> >::value,
        "::boost::unordered::unordered_multimap is not a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is a Boost Random Access Range."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::ptr_multiset<int> >::value,
        "::boost::ptr_multiset is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> > >::value,
        "::boost::heap::d_ary_heap is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not a Boost Random Access Range."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_random_access_range< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not a Boost Random Access Range."
    );
}

#include <odds_and_ends/static_introspection/concept/is_container.hpp>
#include <boost/mpl/bool.hpp>

void test_container()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_container< ::std::pair<char,short> >::value,
        "::std::pair is not a Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_container< ::std::tuple<char,short> >::value,
        "::std::tuple is not a Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::std::array<int,5>,::boost::mpl::true_>::value,
        "::std::array is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::std::vector<int>,::boost::mpl::true_>::value,
        "::std::vector is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::std::deque<int>,::boost::mpl::true_>::value,
        "::std::deque is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::std::forward_list<int>,::boost::mpl::true_>::value,
        "::std::forward_list is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::std::list<int>,::boost::mpl::true_>::value,
        "::std::list is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::std::set<int>,::boost::mpl::true_>::value,
        "::std::set is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::std::multiset<int>,::boost::mpl::true_>::value,
        "::std::multiset is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::std::unordered_set<int>,::boost::mpl::true_>::value,
        "::std::unordered_set is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::std::unordered_multiset<int>,::boost::mpl::true_>::value,
        "::std::unordered_multiset is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::std::map<int,int>,::boost::mpl::true_>::value,
        "::std::map is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::std::multimap<int,int>,::boost::mpl::true_>::value,
        "::std::multimap is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::std::unordered_map<int,int>,::boost::mpl::true_>::value,
        "::std::unordered_map is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::std::unordered_multimap<int,int>,::boost::mpl::true_>::value,
        "::std::unordered_multimap is a C++-Standard Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_container< ::std::stack<int> >::value,
        "::std::stack is not a Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_container< ::std::queue<int> >::value,
        "::std::queue is not a Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_container< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::vector<int>,::boost::mpl::true_>::value,
        "::boost::container::vector is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::stable_vector<int>,::boost::mpl::true_>::value,
        "::boost::container::stable_vector is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::static_vector<int,10>,::boost::mpl::true_>::value,
        "::boost::container::static_vector is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::small_vector<int,5>,::boost::mpl::true_>::value,
        "::boost::container::small_vector is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::devector<int>,::boost::mpl::true_>::value,
        "::boost::container::devector is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::deque<int>,::boost::mpl::true_>::value,
        "::boost::container::deque is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::slist<int>,::boost::mpl::true_>::value,
        "::boost::container::slist is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::list<int>,::boost::mpl::true_>::value,
        "::boost::container::list is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::set<int>,::boost::mpl::true_>::value,
        "::boost::container::set is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::flat_set<int>,::boost::mpl::true_>::value,
        "::boost::container::flat_set is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::unordered::unordered_set<int>,::boost::mpl::true_>::value,
        "::boost::unordered::unordered_set is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::multiset<int>,::boost::mpl::true_>::value,
        "::boost::container::multiset is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::flat_multiset<int>,::boost::mpl::true_>::value,
        "::boost::container::flat_multiset is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::unordered::unordered_multiset<int>,::boost::mpl::true_>::value,
        "::boost::unordered::unordered_multiset is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::map<int,int>,::boost::mpl::true_>::value,
        "::boost::container::map is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::flat_map<int,int>,::boost::mpl::true_>::value,
        "::boost::container::flat_map is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::unordered::unordered_map<int,int>,::boost::mpl::true_>::value,
        "::boost::unordered::unordered_map is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::multimap<int,int>,::boost::mpl::true_>::value,
        "::boost::container::multimap is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::container::flat_multimap<int,int>,::boost::mpl::true_>::value,
        "::boost::container::flat_multimap is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_container<
            ::boost::unordered::unordered_multimap<int,int>,
            ::boost::mpl::true_
        >::value,
        "::boost::unordered::unordered_multimap is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_array<int,5>,::boost::mpl::true_>::value,
        "::boost::ptr_array is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_vector<int>,::boost::mpl::true_>::value,
        "::boost::ptr_vector is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_deque<int>,::boost::mpl::true_>::value,
        "::boost::ptr_deque is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_list<int>,::boost::mpl::true_>::value,
        "::boost::ptr_list is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_set<int>,::boost::mpl::true_>::value,
        "::boost::ptr_set is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_unordered_set<int>,::boost::mpl::true_>::value,
        "::boost::ptr_unordered_set is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_multiset<int>,::boost::mpl::true_>::value,
        "::boost::ptr_multiset is a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_unordered_multiset<int>,::boost::mpl::true_>::value,
        "::boost::ptr_unordered_multiset is a C++-Standard Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_map<int,int>,::boost::mpl::true_>::value,
        "::boost::ptr_map is not a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is a Container with Legacy Input Iterators."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_unordered_map<int,int>,::boost::mpl::true_>::value,
        "::boost::ptr_unordered_map is not a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is a Container with Legacy Input Iterators."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_multimap<int,int>,::boost::mpl::true_>::value,
        "::boost::ptr_multimap is not a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is a Container with Legacy Input Iterators."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_unordered_multimap<int,int>,::boost::mpl::true_>::value,
        "::boost::ptr_unordered_multimap is not a C++-Standard Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is a Container with Legacy Input Iterators."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> > >::value,
        "::boost::heap::d_ary_heap is not a Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not a Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not a Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not a Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_container< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not a Container."
    );
}

#include <odds_and_ends/static_introspection/concept/is_reversible_container.hpp>

void test_reversible_container()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::pair<char,short> >::value,
        "::std::pair is not a Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::tuple<char,short> >::value,
        "::std::tuple is not a Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::array<int,5>,::boost::mpl::true_>::value,
        "::std::array is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::vector<int>,::boost::mpl::true_>::value,
        "::std::vector is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::deque<int>,::boost::mpl::true_>::value,
        "::std::deque is a C++-Standard Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::forward_list<int> >::value,
        "::std::forward_list is not a Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::list<int>,::boost::mpl::true_>::value,
        "::std::list is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::set<int>,::boost::mpl::true_>::value,
        "::std::set is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::multiset<int>,::boost::mpl::true_>::value,
        "::std::multiset is a C++-Standard Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::unordered_set<int> >::value,
        "::std::unordered_set is not a Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is not a Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::map<int,int>,::boost::mpl::true_>::value,
        "::std::map is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::multimap<int,int>,::boost::mpl::true_>::value,
        "::std::multimap is a C++-Standard Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is not a Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is not a Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::stack<int> >::value,
        "::std::stack is not a Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::queue<int> >::value,
        "::std::queue is not a Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::container::vector<int>,::boost::mpl::true_>::value,
        "::boost::container::vector is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_reversible_container<
            ::boost::container::stable_vector<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::stable_vector is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_reversible_container<
            ::boost::container::static_vector<int,10>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::static_vector is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_reversible_container<
            ::boost::container::small_vector<int,5>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::small_vector is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::container::devector<int>,::boost::mpl::true_>::value,
        "::boost::container::devector is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::container::deque<int>,::boost::mpl::true_>::value,
        "::boost::container::deque is a C++-Standard Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not a Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::container::list<int>,::boost::mpl::true_>::value,
        "::boost::container::list is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::container::set<int>,::boost::mpl::true_>::value,
        "::boost::container::set is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::container::flat_set<int>,::boost::mpl::true_>::value,
        "::boost::container::flat_set is a C++-Standard Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is not a Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::container::multiset<int>,::boost::mpl::true_>::value,
        "::boost::container::multiset is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_reversible_container<
            ::boost::container::flat_multiset<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::flat_multiset is a C++-Standard Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::unordered::unordered_multiset<int> >::value,
        "::boost::unordered::unordered_multiset is not a Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::container::map<int,int>,::boost::mpl::true_>::value,
        "::boost::container::map is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_reversible_container<
            ::boost::container::flat_map<int,int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::flat_map is a C++-Standard Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::unordered::unordered_map<int,int> >::value,
        "::boost::unordered::unordered_map is not a Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_reversible_container<
            ::boost::container::multimap<int,int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::multimap is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_reversible_container<
            ::boost::container::flat_multimap<int,int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::flat_multimap is a C++-Standard Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::unordered::unordered_multimap<int,int> >::value,
        "::boost::unordered::unordered_multimap is not a Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::ptr_array<int,5>,::boost::mpl::true_>::value,
        "::boost::ptr_array is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::ptr_vector<int>,::boost::mpl::true_>::value,
        "::boost::ptr_vector is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::ptr_deque<int>,::boost::mpl::true_>::value,
        "::boost::ptr_deque is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::ptr_list<int>,::boost::mpl::true_>::value,
        "::boost::ptr_list is a C++-Standard Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::ptr_set<int>,::boost::mpl::true_>::value,
        "::boost::ptr_set is a C++-Standard Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is not a Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::ptr_multiset<int>,::boost::mpl::true_>::value,
        "::boost::ptr_multiset is a C++-Standard Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is not a Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is a Reversible Container with Bidirectional Traversal Iterators."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is not a Reversible Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is a Reversible Container with Bidirectional Traversal Iterators."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is not a Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_reversible_container<
            ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> >
        >::value,
        "::boost::heap::d_ary_heap is not a Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not a Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not a Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not a Reversible Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_reversible_container< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not a Reversible Container."
    );
}

#include <odds_and_ends/static_introspection/concept/is_indexable_container.hpp>

void test_indexable_container()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::pair<char,short> >::value,
        "::std::pair is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::tuple<char,short> >::value,
        "::std::tuple is not an Indexable Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::array<int,5> >::value,
        "::std::array is an Indexable Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::vector<int> >::value,
        "::std::vector is an Indexable Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::deque<int> >::value,
        "::std::deque is an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::forward_list<int> >::value,
        "::std::forward_list is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::list<int> >::value,
        "::std::list is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::set<int> >::value,
        "::std::set is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::multiset<int> >::value,
        "::std::multiset is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::unordered_set<int> >::value,
        "::std::unordered_set is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::map<int,int> >::value,
        "::std:: is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::multimap<int,int> >::value,
        "::std::multimap is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::stack<int> >::value,
        "::std::stack is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::queue<int> >::value,
        "::std::queue is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not an Indexable Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::vector<int> >::value,
        "::boost::container::vector is an Indexable Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is an Indexable Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::static_vector<int,10> >::value,
        "::boost::container::static_vector is an Indexable Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::small_vector<int,5> >::value,
        "::boost::container::small_vector is an Indexable Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::devector<int> >::value,
        "::boost::container::devector is an Indexable Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::deque<int> >::value,
        "::boost::container::deque is an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::list<int> >::value,
        "::boost::container::list is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::set<int> >::value,
        "::boost::container::set is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::unordered::unordered_multiset<int> >::value,
        "::boost::unordered::unordered_multiset is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::map<int,int> >::value,
        "::boost::container::map is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::unordered::unordered_map<int,int> >::value,
        "::boost::unordered::unordered_map is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::container::flat_multimap<int,int> >::value,
        "::boost::container::flat_multimap is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::unordered::unordered_multimap<int,int> >::value,
        "::boost::unordered::unordered_multimap is not an Indexable Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is an Indexable Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is an Indexable Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::ptr_multiset<int> >::value,
        "::boost::ptr_multiset is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> > >::value,
        "::boost::heap::d_ary_heap is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not an Indexable Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_indexable_container< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not an Indexable Container."
    );
}

#include <odds_and_ends/static_introspection/concept/maybe_contiguous_container.hpp>

void test_contiguous_container()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::pair<char,short> >::value,
        "::std::pair is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::tuple<char,short> >::value,
        "::std::tuple is not a Contiguous Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::array<int,5> >::value,
        "::std::array may be a Contiguous Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::vector<int> >::value,
        "::std::vector may be a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::deque<int> >::value,
        "::std::deque is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::forward_list<int> >::value,
        "::std::forward_list is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::list<int> >::value,
        "::std::list is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::set<int> >::value,
        "::std::set is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::multiset<int> >::value,
        "::std::multiset is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::unordered_set<int> >::value,
        "::std::unordered_set is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::map<int,int> >::value,
        "::std:: is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::multimap<int,int> >::value,
        "::std::multimap is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::stack<int> >::value,
        "::std::stack is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::queue<int> >::value,
        "::std::queue is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a Contiguous Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::vector<int> >::value,
        "::boost::container::vector may be a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is not a Contiguous Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::static_vector<int,10> >::value,
        "::boost::container::static_vector may be a Contiguous Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::small_vector<int,5> >::value,
        "::boost::container::small_vector may be a Contiguous Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::devector<int> >::value,
        "::boost::container::devector may be a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::deque<int> >::value,
        "::boost::container::deque is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::list<int> >::value,
        "::boost::container::list is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::set<int> >::value,
        "::boost::container::set is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::unordered::unordered_multiset<int> >::value,
        "::boost::unordered::unordered_multiset is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::map<int,int> >::value,
        "::boost::container::map is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::unordered::unordered_map<int,int> >::value,
        "::boost::unordered::unordered_map is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::container::flat_multimap<int,int> >::value,
        "::boost::container::flat_multimap is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::unordered::unordered_multimap<int,int> >::value,
        "::boost::unordered::unordered_multimap is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::ptr_multiset<int> >::value,
        "::boost::ptr_multiset is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::maybe_contiguous_container<
            ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> >
        >::value,
        "::boost::heap::d_ary_heap is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not a Contiguous Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::maybe_contiguous_container< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not a Contiguous Container."
    );
}

#include <odds_and_ends/static_introspection/concept/is_allocator_aware.hpp>

void test_allocator_aware()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::std::pair<char,short> >::value,
        "::std::pair is not Allocator-Awar."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::std::tuple<char,short> >::value,
        "::std::tuple is not Allocator-Aware."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::std::array<int,5> >::value,
        "::std::array is not Allocator-Aware."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::std::vector<int>,::boost::mpl::true_>::value,
        "::std::vector is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::std::deque<int>,::boost::mpl::true_>::value,
        "::std::deque is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::std::forward_list<int>,::boost::mpl::true_>::value,
        "::std::forward_list is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::std::list<int>,::boost::mpl::true_>::value,
        "::std::list is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::std::set<int>,::boost::mpl::true_>::value,
        "::std::set is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::std::multiset<int>,::boost::mpl::true_>::value,
        "::std::multiset is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::std::unordered_set<int>,::boost::mpl::true_>::value,
        "::std::unordered_set is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::std::unordered_multiset<int>,
            ::boost::mpl::true_
        >::value,
        "::std::unordered_multiset is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::std::map<int,int>,::boost::mpl::true_>::value,
        "::std::map is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::std::multimap<int,int>,::boost::mpl::true_>::value,
        "::std::multimap is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::std::unordered_map<int,int>,
            ::boost::mpl::true_
        >::value,
        "::std::unordered_map is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::std::unordered_multimap<int,int>,
            ::boost::mpl::true_
        >::value,
        "::std::unordered_multimap is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::std::stack<int> >::value,
        "::std::stack is not Allocator-Aware."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::std::queue<int> >::value,
        "::std::queue is not Allocator-Aware."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not Allocator-Aware."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::vector<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::vector is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::stable_vector<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::stable_vector is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::static_vector<int,10>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::static_vector is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::small_vector<int,5>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::small_vector is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::devector<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::devector is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::deque<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::deque is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::slist<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::slist is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::list<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::list is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::set<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::set is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::flat_set<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::flat_set is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::unordered::unordered_set<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::unordered::unordered_set is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::multiset<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::multiset is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::flat_multiset<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::flat_multiset is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::unordered::unordered_multiset<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::unordered::unordered_multiset is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::map<int,int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::map is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::flat_map<int,int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::flat_map is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::unordered::unordered_map<int,int>,
            ::boost::mpl::true_
        >::value,
        "::boost::unordered::unordered_map is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::multimap<int,int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::multimap is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::container::flat_multimap<int,int>,
            ::boost::mpl::true_
        >::value,
        "::boost::container::flat_multimap is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::unordered::unordered_multimap<int,int>,
            ::boost::mpl::true_
        >::value,
        "::boost::unordered::unordered_multimap is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is not Allocator-Aware."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::boost::ptr_vector<int>,::boost::mpl::true_>::value,
        "::boost::ptr_vector is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::boost::ptr_deque<int>,::boost::mpl::true_>::value,
        "::boost::ptr_deque is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::boost::ptr_list<int>,::boost::mpl::true_>::value,
        "::boost::ptr_list is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::boost::ptr_set<int>,::boost::mpl::true_>::value,
        "::boost::ptr_set is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is Allocator-Aware with Legacy Input Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::boost::ptr_multiset<int>,::boost::mpl::true_>::value,
        "::boost::ptr_multiset is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::boost::ptr_unordered_multiset<int> >::value,
        "ptr_unordered_multiset is Allocator-Aware with Legacy Input Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is Allocator-Aware with Legacy Input Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is Allocator-Aware with Legacy Input Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is Allocator-Aware with Legacy Input Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_allocator_aware< ::boost::ptr_unordered_multimap<int,int> >::value,
        "ptr_unordered_multimap is Allocator-Aware with Legacy Input Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::heap::priority_queue<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::heap::priority_queue is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> >,
            ::boost::mpl::true_
        >::value,
        "::boost::heap::d_ary_heap is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::heap::binomial_heap<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::heap::binomial_heap is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::heap::fibonacci_heap<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::heap::fibonacci_heap is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::heap::pairing_heap<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::heap::pairing_heap is Allocator-Aware with Legacy Forward Iterators."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_allocator_aware<
            ::boost::heap::skew_heap<int>,
            ::boost::mpl::true_
        >::value,
        "::boost::heap::skew_heap is Allocator-Aware with Legacy Forward Iterators."
    );
}

#include <odds_and_ends/static_introspection/concept/is_pointer_container.hpp>

void test_pointer_container()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::pair<char,short> >::value,
        "::std::pair is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::tuple<char,short> >::value,
        "::std::tuple is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::array<int,5> >::value,
        "::std::array is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::vector<int> >::value,
        "::std::vector is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::deque<int> >::value,
        "::std::deque is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::forward_list<int> >::value,
        "::std::forward_list is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::list<int> >::value,
        "::std::list is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::set<int> >::value,
        "::std::set is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::multiset<int> >::value,
        "::std::multiset is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::unordered_set<int> >::value,
        "::std::unordered_set is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::map<int,int> >::value,
        "::std::map is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::multimap<int,int> >::value,
        "::std::multimap is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::stack<int> >::value,
        "::std::stack is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::queue<int> >::value,
        "::std::queue is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::vector<int> >::value,
        "::boost::container::vector is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::static_vector<int,10> >::value,
        "::boost::container::static_vector is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::small_vector<int,5> >::value,
        "::boost::container::small_vector is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::devector<int> >::value,
        "::boost::container::devector is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::deque<int> >::value,
        "::boost::container::deque is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::list<int> >::value,
        "::boost::container::list is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::set<int> >::value,
        "::boost::container::set is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::unordered::unordered_multiset<int> >::value,
        "::boost::unordered::unordered_multiset is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::map<int,int> >::value,
        "::boost::container::map is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::unordered::unordered_map<int,int> >::value,
        "::boost::unordered::unordered_map is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::container::flat_multimap<int,int> >::value,
        "::boost::container::flat_multimap is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::unordered::unordered_multimap<int,int> >::value,
        "::boost::unordered::unordered_multimap is not a Boost Pointer Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is a Boost Pointer Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is a Boost Pointer Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is a Boost Pointer Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is a Boost Pointer Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is a Boost Pointer Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is a Boost Pointer Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::ptr_multiset<int> >::value,
        "::boost:ptr_multiset is a Boost Pointer Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is a Boost Pointer Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is a Boost Pointer Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is a Boost Pointer Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is a Boost Pointer Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> > >::value,
        "::boost::heap::d_ary_heap is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not a Boost Pointer Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_pointer_container< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not a Boost Pointer Container."
    );
}

#include <odds_and_ends/static_introspection/concept/is_legacy_associative_container.hpp>

void test_legacy_associative_container()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::pair<char,short> >::value,
        "::std::pair is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::tuple<char,short> >::value,
        "::std::tuple is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::array<int,5> >::value,
        "::std::array is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::vector<int> >::value,
        "::std::vector is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::deque<int> >::value,
        "::std::deque is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::forward_list<int> >::value,
        "::std::forward_list is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::list<int> >::value,
        "::std::list is not a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::set<int> >::value,
        "::std::set is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::multiset<int> >::value,
        "::std::multiset is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::unordered_set<int> >::value,
        "::std::unordered_set is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::map<int,int> >::value,
        "::std::map is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::multimap<int,int> >::value,
        "::std::multimap is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::stack<int> >::value,
        "::std::stack is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::queue<int> >::value,
        "::std::queue is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::vector<int> >::value,
        "::boost::container::vector is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::static_vector<int,10> >::value,
        "::boost::container::static_vector is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::small_vector<int,5> >::value,
        "::boost::container::small_vector is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::devector<int> >::value,
        "::boost::container::devector is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::deque<int> >::value,
        "::boost::container::deque is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::list<int> >::value,
        "::boost::container::list is not a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::set<int> >::value,
        "::boost::container::set is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::unordered::unordered_multiset<int> >::value,
        "::boost::unordered::unordered_multiset is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::map<int,int> >::value,
        "::boost::container::map is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::unordered::unordered_map<int,int> >::value,
        "::boost::unordered::unordered_map is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::container::flat_multimap<int,int> >::value,
        "::boost::container::flat_multimap is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_legacy_associative_container<
            ::boost::unordered::unordered_multimap<int,int>
        >::value,
        "::boost::unordered::unordered_multimap is a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is not a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::ptr_set<int> >::value,
        "::boost:: is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::ptr_multiset<int> >::value,
        "::boost::ptr_multiset is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is a Legacy Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_associative_container<
            ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> >
        >::value,
        "::boost::heap::d_ary_heap is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not a Legacy Associative Container."
    );
}

#include <odds_and_ends/static_introspection/concept/is_legacy_simple_associative_container.hpp>

void test_legacy_simple_associative_container()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::pair<char,short> >::value,
        "::std:: is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::tuple<char,short> >::value,
        "::std:: is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::array<int,5> >::value,
        "::std::array is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::vector<int> >::value,
        "::std::vector is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::deque<int> >::value,
        "::std::deque is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::forward_list<int> >::value,
        "::std::forward_list is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::list<int> >::value,
        "::std::list is not a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::set<int> >::value,
        "::std::set is a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::multiset<int> >::value,
        "::std::multiset is a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::unordered_set<int> >::value,
        "::std::unordered_set is a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::map<int,int> >::value,
        "::std::map is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::multimap<int,int> >::value,
        "::std::multimap is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::stack<int> >::value,
        "::std::stack is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::queue<int> >::value,
        "::std::queue is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::container::vector<int> >::value,
        "::boost::container::vector is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_simple_associative_container<
            ::boost::container::static_vector<int,10>
        >::value,
        "::boost::container::static_vector is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_simple_associative_container<
            ::boost::container::small_vector<int,5>
        >::value,
        "::boost::container::small_vector is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::container::devector<int> >::value,
        "::boost::container::devector is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::container::deque<int> >::value,
        "::boost::container::deque is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::container::list<int> >::value,
        "::boost::container::list is not a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::container::set<int> >::value,
        "::boost::container::set is a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_legacy_simple_associative_container<
            ::boost::unordered::unordered_multiset<int>
        >::value,
        "::boost::unordered::unordered_multiset is a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::container::map<int,int> >::value,
        "::boost::container::map is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_simple_associative_container<
            ::boost::unordered::unordered_map<int,int>
        >::value,
        "::boost::unordered::unordered_map is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_simple_associative_container<
            ::boost::container::flat_multimap<int,int>
        >::value,
        "::boost::container::flat_multimap is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_simple_associative_container<
            ::boost::unordered::unordered_multimap<int,int>
        >::value,
        "::boost::unordered::unordered_multimap is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is not a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::ptr_multiset<int> >::value,
        "::boost::ptr_multiset is a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_simple_associative_container<
            ::boost::ptr_unordered_multimap<int,int>
        >::value,
        "::boost::ptr_unordered_multimap is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_simple_associative_container<
            ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> >
        >::value,
        "::boost::heap::d_ary_heap is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not a Legacy Simple Associative Container."
    );
}

#include <odds_and_ends/static_introspection/concept/is_legacy_pair_associative_container.hpp>

void test_legacy_pair_associative_container()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::pair<char,short> >::value,
        "::std::pair is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::tuple<char,short> >::value,
        "::std::tuple is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::array<int,5> >::value,
        "::std::array is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::vector<int> >::value,
        "::std::vector is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::deque<int> >::value,
        "::std::deque is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::forward_list<int> >::value,
        "::std::forward_list is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::list<int> >::value,
        "::std::list is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::set<int> >::value,
        "::std::set is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::multiset<int> >::value,
        "::std::multiset is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::unordered_set<int> >::value,
        "::std::unordered_set is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is not a Legacy Pair Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::map<int,int> >::value,
        "::std::map is a Legacy Pair Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::multimap<int,int> >::value,
        "::std::multimap is a Legacy Pair Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is a Legacy Pair Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::stack<int> >::value,
        "::std::stack is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::queue<int> >::value,
        "::std::queue is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::container::vector<int> >::value,
        "::boost::container::vector is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_pair_associative_container<
            ::boost::container::static_vector<int,10>
        >::value,
        "::boost::container::static_vector is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::container::small_vector<int,5> >::value,
        "::boost::container::small_vector is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::container::devector<int> >::value,
        "::boost::container::devector is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::container::deque<int> >::value,
        "::boost::container::deque is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::container::list<int> >::value,
        "::boost::container::list is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::container::set<int> >::value,
        "::boost::container::set is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_pair_associative_container<
            ::boost::unordered::unordered_multiset<int>
        >::value,
        "::boost::unordered::unordered_multiset is not a Legacy Pair Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::container::map<int,int> >::value,
        "::boost::container::map is not a Legacy Pair Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is not a Legacy Pair Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_legacy_pair_associative_container<
            ::boost::unordered::unordered_map<int,int>
        >::value,
        "::boost::unordered::unordered_map is a Legacy Pair Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is not a Legacy Pair Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_legacy_pair_associative_container<
            ::boost::container::flat_multimap<int,int>
        >::value,
        "::boost::container::flat_multimap is not a Legacy Pair Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_legacy_pair_associative_container<
            ::boost::unordered::unordered_multimap<int,int>
        >::value,
        "::boost::unordered::unordered_multimap is a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::ptr_multiset<int> >::value,
        "::boost::ptr_multiset is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is not a Legacy Pair Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is a Legacy Pair Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is a Legacy Pair Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is a Legacy Pair Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_associative_container<
            ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> >
        >::value,
        "::boost::heap::d_ary_heap is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_associative_container< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not a Legacy Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_pair_associative_container<
            ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> >
        >::value,
        "::boost::heap::d_ary_heap is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not a Legacy Pair Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not a Legacy Pair Associative Container."
    );
}

#include <odds_and_ends/static_introspection/concept/is_legacy_sorted_associative_container.hpp>

void test_legacy_sorted_associative_container()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::pair<char,short> >::value,
        "::std::pair is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::tuple<char,short> >::value,
        "::std::tuple is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::array<int,5> >::value,
        "::std::array is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::vector<int> >::value,
        "::std::vector is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::deque<int> >::value,
        "::std::deque is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::forward_list<int> >::value,
        "::std::forward_list is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::list<int> >::value,
        "::std::list is not a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::set<int> >::value,
        "::std::set is a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::multiset<int> >::value,
        "::std::multiset is a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::unordered_set<int> >::value,
        "::std::unordered_set is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is not a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::map<int,int> >::value,
        "::std::map is a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::multimap<int,int> >::value,
        "::std::multimap is a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::stack<int> >::value,
        "::std::stack is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::queue<int> >::value,
        "::std::queue is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::container::vector<int> >::value,
        "::boost::container::vector is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_sorted_associative_container<
            ::boost::container::static_vector<int,10>
        >::value,
        "::boost::container::static_vector is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_sorted_associative_container<
            ::boost::container::small_vector<int,5>
        >::value,
        "::boost::container::small_vector is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::container::devector<int> >::value,
        "::boost::container::devector is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::container::deque<int> >::value,
        "::boost::container::deque is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::container::list<int> >::value,
        "::boost::container::list is not a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::container::set<int> >::value,
        "::boost::container::set is a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is not a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_sorted_associative_container<
            ::boost::unordered::unordered_multiset<int>
        >::value,
        "::boost::unordered::unordered_multiset is not a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::container::map<int,int> >::value,
        "::boost::container::map is a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_sorted_associative_container<
            ::boost::unordered::unordered_map<int,int>
        >::value,
        "::boost::unordered::unordered_map is not a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_legacy_sorted_associative_container<
            ::boost::container::flat_multimap<int,int>
        >::value,
        "::boost::container::flat_multimap is a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_sorted_associative_container<
            ::boost::unordered::unordered_multimap<int,int>
        >::value,
        "::boost::unordered::unordered_multimap is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is not a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is not a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::ptr_multiset<int> >::value,
        "::boost::ptr_multiset is a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is not a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is not a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_sorted_associative_container<
            ::boost::ptr_unordered_multimap<int,int>
        >::value,
        "::boost::ptr_unordered_multimap is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_sorted_associative_container<
            ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> >
        >::value,
        "::boost::heap::d_ary_heap is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not a Legacy Sorted Associative Container."
    );
}

#include <odds_and_ends/static_introspection/concept/is_legacy_unordered_associative_container.hpp>

void test_legacy_unordered_associative_container()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::pair<char,short> >::value,
        "::std::pair is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::tuple<char,short> >::value,
        "::std::tuple is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::array<int,5> >::value,
        "::std::array is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::vector<int> >::value,
        "::std::vector is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::deque<int> >::value,
        "::std::deque is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::forward_list<int> >::value,
        "::std::forward_list is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::list<int> >::value,
        "::std::list is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::set<int> >::value,
        "::std::set is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::multiset<int> >::value,
        "::std::multiset is not a Legacy Unordered Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::unordered_set<int> >::value,
        "::std::unordered_set is a Legacy Unordered Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::map<int,int> >::value,
        "::std::map is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::multimap<int,int> >::value,
        "::std::multimap is not a Legacy Unordered Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is a Legacy Unordered Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::stack<int> >::value,
        "::std::stack is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::queue<int> >::value,
        "::std::queue is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::container::vector<int> >::value,
        "::boost::container::vector is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_unordered_associative_container<
            ::boost::container::stable_vector<int>
        >::value,
        "::boost::container::stable_vector is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_unordered_associative_container<
            ::boost::container::static_vector<int,10>
        >::value,
        "::boost::container::static_vector is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_unordered_associative_container<
            ::boost::container::small_vector<int,5>
        >::value,
        "::boost::container::small_vector is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::container::devector<int> >::value,
        "::boost::container::devector is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::container::deque<int> >::value,
        "::boost::container::deque is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::container::list<int> >::value,
        "::boost::container::list is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::container::set<int> >::value,
        "::boost::container::set is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is not a Legacy Unordered Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_legacy_unordered_associative_container<
            ::boost::unordered::unordered_set<int>
        >::value,
        "::boost::unordered::unordered_set is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_unordered_associative_container<
            ::boost::container::flat_multiset<int>
        >::value,
        "::boost::container::flat_multiset is not a Legacy Unordered Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_legacy_unordered_associative_container<
            ::boost::unordered::unordered_multiset<int>
        >::value,
        "::boost::unordered::unordered_multiset is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::container::map<int,int> >::value,
        "::boost::container::map is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_unordered_associative_container<
            ::boost::container::flat_map<int,int>
        >::value,
        "::boost::container::flat_map is not a Legacy Unordered Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_legacy_unordered_associative_container<
            ::boost::unordered::unordered_map<int,int>
        >::value,
        "::boost::unordered::unordered_map is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_unordered_associative_container<
            ::boost::container::multimap<int,int>
        >::value,
        "::boost::container::multimap is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_unordered_associative_container<
            ::boost::container::flat_multimap<int,int>
        >::value,
        "::boost::container::flat_multimap is not a Legacy Unordered Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_legacy_unordered_associative_container<
            ::boost::unordered::unordered_multimap<int,int>
        >::value,
        "::boost::unordered::unordered_multimap is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is not a Legacy Unordered Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::ptr_multiset<int> >::value,
        "::boost::ptr_multiset is not a Legacy Unordered Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_legacy_unordered_associative_container<
            ::boost::ptr_unordered_multiset<int>
        >::value,
        "::boost::ptr_unordered_multiset is a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is not a Legacy Unordered Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is not a Legacy Unordered Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_legacy_unordered_associative_container<
            ::boost::ptr_unordered_multimap<int,int>
        >::value,
        "::boost::ptr_unordered_multimap is a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_legacy_unordered_associative_container<
            ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> >
        >::value,
        "::boost::heap::d_ary_heap is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not a Legacy Unordered Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_unordered_associative_container< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not a Legacy Unordered Associative Container."
    );
}

#include <odds_and_ends/static_introspection/concept/is_queue.hpp>

void test_queue()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::pair<char,short> >::value,
        "::std::pair is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::tuple<char,short> >::value,
        "::std::tuple is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::array<int,5> >::value,
        "::std::array is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::vector<int> >::value,
        "::std::vector is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::deque<int> >::value,
        "::std::deque is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::forward_list<int> >::value,
        "::std::forward_list is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::list<int> >::value,
        "::std::list is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::set<int> >::value,
        "::std::set is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::multiset<int> >::value,
        "::std::multiset is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::unordered_set<int> >::value,
        "::std::unordered_set is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::map<int,int> >::value,
        "::std::map is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::multimap<int,int> >::value,
        "::std::multimap is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::stack<int> >::value,
        "::std::stack is not a Queue."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::queue<int> >::value,
        "::std::queue is a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::vector<int> >::value,
        "::boost::container::vector is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::static_vector<int,10> >::value,
        "::boost::container::static_vector is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::small_vector<int,5> >::value,
        "::boost::container::small_vector is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::devector<int> >::value,
        "::boost::container::devector is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::deque<int> >::value,
        "::boost::container::deque is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::list<int> >::value,
        "::boost::container::list is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::set<int> >::value,
        "::boost::container::set is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::unordered::unordered_multiset<int> >::value,
        "::boost::unordered::unordered_multiset is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::map<int,int> >::value,
        "::boost::container::map is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::unordered::unordered_map<int,int> >::value,
        "::boost::unordered::unordered_map is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::container::flat_multimap<int,int> >::value,
        "::boost::container::flat_multimap is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::unordered::unordered_multimap<int,int> >::value,
        "::boost::unordered::unordered_multimap is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::ptr_multiset<int> >::value,
        "::boost:ptr_multiset is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> > >::value,
        "::boost::heap::d_ary_heap is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is not a Queue."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_queue< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is not a Queue."
    );
}

#include <odds_and_ends/static_introspection/concept/is_stack_or_heap.hpp>

void test_stack_or_heap()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::pair<char,short> >::value,
        "::std::pair is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::tuple<char,short> >::value,
        "::std::tuple is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::array<int,5> >::value,
        "::std::array is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::vector<int> >::value,
        "::std::vector is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::deque<int> >::value,
        "::std::deque is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::forward_list<int> >::value,
        "::std::forward_list is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::list<int> >::value,
        "::std::list is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::set<int> >::value,
        "::std::set is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::multiset<int> >::value,
        "::std::multiset is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::unordered_set<int> >::value,
        "::std::unordered_set is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::map<int,int> >::value,
        "::std::map is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::multimap<int,int> >::value,
        "::std::multimap is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is neither a Stack nor a Heap."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::stack<int> >::value,
        "::std::stack is either a Stack or a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::queue<int> >::value,
        "::std::queue is neither a Stack nor a Heap."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::std::priority_queue<int> >::value,
        "::std::priority_queue is either a Stack or a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::vector<int> >::value,
        "::boost::container::vector is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::static_vector<int,10> >::value,
        "::boost::container::static_vector is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::small_vector<int,5> >::value,
        "::boost::container::small_vector is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::devector<int> >::value,
        "::boost::container::devector is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::deque<int> >::value,
        "::boost::container::deque is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::slist<int> >::value,
        "::boost::container::slist is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::list<int> >::value,
        "::boost::container::list is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::set<int> >::value,
        "::boost::container::set is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::unordered::unordered_multiset<int> >::value,
        "::boost::unordered::unordered_multiset is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::map<int,int> >::value,
        "::boost::container::map is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::unordered::unordered_map<int,int> >::value,
        "::boost::unordered::unordered_map is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::container::flat_multimap<int,int> >::value,
        "::boost::container::flat_multimap is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::unordered::unordered_multimap<int,int> >::value,
        "::boost::unordered::unordered_multimap is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::ptr_multiset<int> >::value,
        "::boost:ptr_multiset is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is neither a Stack nor a Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is neither a Stack nor a Heap."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is either a Stack or a Heap."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> > >::value,
        "::boost::heap::d_ary_heap is either a Stack or a Heap."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is either a Stack or a Heap."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is either a Stack or a Heap."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is either a Stack or a Heap."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_stack_or_heap< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is either a Stack or a Heap."
    );
}

#include <odds_and_ends/static_introspection/concept/is_mergeable_heap.hpp>

void test_mergeable_heap()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::pair<char,short> >::value,
        "::std::pair is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::tuple<char,short> >::value,
        "::std::tuple is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::array<int,5> >::value,
        "::std::array is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::vector<int> >::value,
        "::std::vector is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::deque<int> >::value,
        "::std::deque is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::forward_list<int> >::value,
        "::std::forward_list is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::list<int> >::value,
        "::std::list is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::set<int> >::value,
        "::std::set is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::multiset<int> >::value,
        "::std::multiset is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::unordered_set<int> >::value,
        "::std::unordered_set is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::unordered_multiset<int> >::value,
        "::std::unordered_multiset is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::map<int,int> >::value,
        "::std::map is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::multimap<int,int> >::value,
        "::std::multimap is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::unordered_map<int,int> >::value,
        "::std::unordered_map is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::unordered_multimap<int,int> >::value,
        "::std::unordered_multimap is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::stack<int> >::value,
        "::std::stack is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::queue<int> >::value,
        "::std::queue is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::std::priority_queue<int> >::value,
        "::std::priority_queue is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::vector<int> >::value,
        "::boost::container::vector is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::stable_vector<int> >::value,
        "::boost::container::stable_vector is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::static_vector<int,10> >::value,
        "::boost::container::static_vector is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::small_vector<int,5> >::value,
        "::boost::container::small_vector is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::devector<int> >::value,
        "::boost::container::devector is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::deque<int> >::value,
        "::boost::container::deque is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::slist<int> >::value,
        "::boost::container::slist is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::list<int> >::value,
        "::boost::container::list is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::set<int> >::value,
        "::boost::container::set is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::flat_set<int> >::value,
        "::boost::container::flat_set is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::unordered::unordered_set<int> >::value,
        "::boost::unordered::unordered_set is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::multiset<int> >::value,
        "::boost::container::multiset is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::flat_multiset<int> >::value,
        "::boost::container::flat_multiset is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::unordered::unordered_multiset<int> >::value,
        "::boost::unordered::unordered_multiset is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::map<int,int> >::value,
        "::boost::container::map is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::flat_map<int,int> >::value,
        "::boost::container::flat_map is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::unordered::unordered_map<int,int> >::value,
        "::boost::unordered::unordered_map is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::multimap<int,int> >::value,
        "::boost::container::multimap is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::container::flat_multimap<int,int> >::value,
        "::boost::container::flat_multimap is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::unordered::unordered_multimap<int,int> >::value,
        "::boost::unordered::unordered_multimap is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::ptr_array<int,5> >::value,
        "::boost::ptr_array is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::ptr_vector<int> >::value,
        "::boost::ptr_vector is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::ptr_deque<int> >::value,
        "::boost::ptr_deque is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::ptr_list<int> >::value,
        "::boost::ptr_list is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::ptr_set<int> >::value,
        "::boost::ptr_set is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::ptr_unordered_set<int> >::value,
        "::boost::ptr_unordered_set is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::ptr_multiset<int> >::value,
        "::boost:ptr_multiset is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::ptr_unordered_multiset<int> >::value,
        "::boost::ptr_unordered_multiset is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::ptr_map<int,int> >::value,
        "::boost::ptr_map is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::ptr_unordered_map<int,int> >::value,
        "::boost::ptr_unordered_map is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::ptr_multimap<int,int> >::value,
        "::boost::ptr_multimap is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::ptr_unordered_multimap<int,int> >::value,
        "::boost::ptr_unordered_multimap is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::heap::priority_queue<int> >::value,
        "::boost::heap::priority_queue is not a Mergeable Heap."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::heap::d_ary_heap<int,::boost::heap::arity<2> > >::value,
        "::boost::heap::d_ary_heap is not a Mergeable Heap."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::heap::binomial_heap<int> >::value,
        "::boost::heap::binomial_heap is a Mergeable Heap."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::heap::fibonacci_heap<int> >::value,
        "::boost::heap::fibonacci_heap is a Mergeable Heap."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::heap::pairing_heap<int> >::value,
        "::boost::heap::pairing_heap is a Mergeable Heap."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_mergeable_heap< ::boost::heap::skew_heap<int> >::value,
        "::boost::heap::skew_heap is a Mergeable Heap."
    );
}

#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
    test_runtime_pair();
    test_std_tuple();
    test_single_pass_range();
    test_forward_range();
    test_bidirectional_range();
    test_indexable_range();
    test_random_access_range();
    test_container();
    test_reversible_container();
    test_indexable_container();
    test_contiguous_container();
    test_allocator_aware();
    test_pointer_container();
    test_legacy_associative_container();
    test_legacy_simple_associative_container();
    test_legacy_pair_associative_container();
    test_legacy_sorted_associative_container();
    test_legacy_unordered_associative_container();
    test_queue();
    test_stack_or_heap();
    test_mergeable_heap();
    return ::boost::report_errors();
}
