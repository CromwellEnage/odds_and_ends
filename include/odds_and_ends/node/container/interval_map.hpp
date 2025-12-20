// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__CONTAINER__INTERVAL_MAP_HPP
#define ODDS_AND_ENDS__NODE__CONTAINER__INTERVAL_MAP_HPP

#include <cstddef>
#include <type_traits>
#include <functional>
#include <utility>
#include <memory>
#include <odds_and_ends/node/data.hpp>
#include <odds_and_ends/node/tree/base.hpp>
#include <odds_and_ends/node/tree/binary.hpp>
#include <odds_and_ends/node/tree/with_size.hpp>
#include <odds_and_ends/node/iterator/in_order_tree.hpp>
#include <odds_and_ends/node/iterator/indirect.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <odds_and_ends/static_introspection/concept/is_allocator.hpp>
#include <odds_and_ends/static_introspection/concept/is_indexable_iterator.hpp>
//#include <boost/numeric/interval.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/quote.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <
        typename Key,
        typename Mapped,
        typename NodeParentGeneratorList,
        typename Balancer,
        typename Compare = ::std::less<Key>,
        typename Size = ::std::size_t,
        typename PtrXForm = ::boost::mpl::quote1< ::std::add_pointer>,
        typename AllocXForm = ::boost::mpl::quote1< ::std::allocator>
    >
    class interval_map
    {
        struct _enabler
        {
        };

    public:
        typedef ::odds_and_ends::node::container
        ::interval_map<Key,Mapped,NodeParentGeneratorList,Balancer,PtrXForm,AllocXForm> type;
        typedef Size size_type;
        typedef Key key_type;
        typedef Mapped mapped_type;
        typedef Compare key_compare;

        class interval_type
        {
            key_type _l;
            key_type _u;

        public:
            inline interval_type(key_type const& l, key_type const& u) : _l(l), _u(u)
            {
            }

            inline interval_type(interval_type const& copy) : _l(copy._l), _u(copy._u)
            {
            }

            inline key_type const& lower() const
            {
                return this->_l;
            }

            inline key_type const& upper() const
            {
                return this->_u;
            }
        };

//        typedef ::boost::numeric::interval<Key> interval_type;
        typedef ::std::pair<interval_type const,Mapped> value_type;
        typedef value_type& reference;
        typedef value_type const& const_reference;
        typedef typename ::boost::mpl::apply_wrap1<PtrXForm,value_type>::type pointer;
        typedef typename ::boost::mpl::apply_wrap1<PtrXForm,value_type const>::type const_pointer;
        typedef ::odds_and_ends::composite_type::composite_type<
            typename ::boost::mpl::push_front<
                typename ::boost::mpl::push_front<
                    typename ::boost::mpl::push_front<
                        typename ::boost::mpl::push_front<
                            NodeParentGeneratorList,
                            ::odds_and_ends::node::tree::with_size<Size>
                        >::type,
                        ::odds_and_ends::node::tree::binary<>
                    >::type,
                    ::odds_and_ends::node::tree::base<PtrXForm>
                >::type,
                ::odds_and_ends::node::data<value_type>
            >::type
        > node_type;
        typedef typename ::boost::mpl::apply_wrap1<AllocXForm,node_type>::type allocator_type;

        class value_compare
        {
            key_compare _comp;

            inline value_compare() : _comp()
            {
            }

            inline value_compare(key_compare const& comp) : _comp(comp)
            {
            }

        public:
            inline bool operator()(const_reference lhs, const_reference rhs) const
            {
                return this->_comp(lhs.first, rhs.first);
            }

            template <typename K>
            inline bool operator()(K const& k, const_reference rhs) const
            {
                return this->_comp(k, rhs.first.lower());
            }

            template <typename K>
            inline bool operator()(const_reference lhs, K const& k) const
            {
                return this->_comp(lhs.first.upper(), k);
            }

            friend class interval_map;
        };

    private:
        typedef ::odds_and_ends::node
        ::in_order_tree_iterator<node_type,::boost::mpl::false_> _itr_t;
        typedef ::odds_and_ends::node
        ::in_order_tree_iterator<node_type const,::boost::mpl::false_> _c_itr_t;
        typedef ::odds_and_ends::node
        ::in_order_tree_iterator<node_type,::boost::mpl::true_> _r_itr_t;
        typedef ::odds_and_ends::node
        ::in_order_tree_iterator<node_type const,::boost::mpl::true_> _c_r_itr_t;

    public:
        typedef ::odds_and_ends::node::indirect_iterator<_itr_t,PtrXForm> iterator;
        typedef ::odds_and_ends::node::indirect_iterator<_c_itr_t,PtrXForm> const_iterator;
        typedef ::odds_and_ends::node::indirect_iterator<_r_itr_t,PtrXForm> reverse_iterator;
        typedef ::odds_and_ends::node
        ::indirect_iterator<_c_r_itr_t,PtrXForm> const_reverse_iterator;

    private:
        typedef typename node_type::traits::const_pointer _node_const_ptr_t;
        typedef typename node_type::traits::pointer _node_ptr_t;

        key_compare _comp;
        allocator_type _alloc;
        _node_ptr_t _root_ptr;

    public:
        template <typename Alloc>
        interval_map(
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        interval_map(
            key_compare const& comp,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        interval_map(
            interval_map const& copy,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        interval_map(
            interval_map const& copy,
            key_compare const& comp,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <
            typename K,
            typename M,
            typename N,
            typename B,
            typename C,
            typename S,
            typename P,
            typename A
        >
        interval_map(
            interval_map<K,M,N,B,C,S,P,A> const& copy,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<K,Key>,
                    ::std::is_convertible<M,Mapped>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <
            typename K,
            typename M,
            typename N,
            typename B,
            typename C,
            typename S,
            typename P,
            typename A
        >
        interval_map(
            interval_map<K,M,N,B,C,S,P,A> const& copy,
            key_compare const& comp,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<K,Key>,
                    ::std::is_convertible<M,Mapped>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <
            typename K,
            typename M,
            typename N,
            typename B,
            typename C,
            typename S,
            typename P,
            typename A,
            typename Alloc
        >
        interval_map(
            interval_map<K,M,N,B,C,S,P,A> const& copy,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::if_<
                        ::std::is_convertible<K,Key>,
                        ::std::is_convertible<M,Mapped>,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <
            typename K,
            typename M,
            typename N,
            typename B,
            typename C,
            typename S,
            typename P,
            typename A,
            typename Alloc
        >
        interval_map(
            interval_map<K,M,N,B,C,S,P,A> const& copy,
            key_compare const& comp,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::if_<
                        ::std::is_convertible<K,Key>,
                        ::std::is_convertible<M,Mapped>,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        interval_map(
            interval_map&& source,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        interval_map(
            interval_map&& source,
            key_compare const& comp,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Iterator>
        interval_map(
            Iterator itr_begin,
            Iterator itr_end,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_indexable_iterator<Iterator>,
                _enabler
            >::type = _enabler()
        );

        template <typename Iterator>
        interval_map(
            Iterator itr_begin,
            Iterator itr_end,
            key_compare const& comp,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_indexable_iterator<Iterator>,
                _enabler
            >::type = _enabler()
        );

        template <typename Iterator, typename Alloc>
        interval_map(
            Iterator itr_begin,
            Iterator itr_end,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection
                    ::concept::is_indexable_iterator<Iterator>,
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename Iterator, typename Alloc>
        interval_map(
            Iterator itr_begin,
            Iterator itr_end,
            key_compare const& comp,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection
                    ::concept::is_indexable_iterator<Iterator>,
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        interval_map();
        explicit interval_map(key_compare const& comp);
        interval_map(interval_map const& copy);
        interval_map(interval_map const& copy, key_compare const& comp);
        interval_map(interval_map&& source);
        interval_map(interval_map&& source, key_compare const& comp);
        ~interval_map();
        interval_map& operator=(interval_map const& copy);
        interval_map& operator=(interval_map&& source);
        allocator_type get_allocator() const;
        bool empty() const;
        size_type size() const;
        void clear();
        const_iterator cbegin() const;
        const_iterator begin() const;
        iterator begin();
        const_iterator cend() const;
        const_iterator end() const;
        iterator end();
        const_reverse_iterator crbegin() const;
        const_reverse_iterator rbegin() const;
        reverse_iterator rbegin();
        const_reverse_iterator crend() const;
        const_reverse_iterator rend() const;
        reverse_iterator rend();
        const_iterator find(key_type const& key) const;
        iterator find(key_type const& key);

        template <typename K>
        const_iterator find(K const& k) const;

        template <typename K>
        iterator find(K const& k);

    private:
        template <typename Iterator>
        void _fill_construct(Iterator itr, Iterator itr_end);

        template <typename Iterator>
        void _copy_construct(Iterator itr, Iterator itr_end, size_type const& copy_size);
    };
}}}  // namespace odds_and_ends::node::container

#include <tuple>
#include <utility>
#include <algorithm>
#include <odds_and_ends/node/iterator/breadth_first_tree.hpp>
#include <odds_and_ends/node/iterator/post_order_tree.hpp>
#include <odds_and_ends/node/algorithm/binary_tree_descendant.hpp>
#include <odds_and_ends/node/algorithm/is_ancestor_of.hpp>
#include <odds_and_ends/node/algorithm/increment_in_binary_tree.hpp>
#include <odds_and_ends/node/container/queue.hpp>
#include <boost/utility/value_init.hpp>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map() :
        _comp(), _alloc(), _root_ptr(nullptr)
    {
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        key_compare const& comp
    ) : _comp(comp), _alloc(), _root_ptr(nullptr)
    {
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Alloc>
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(), _alloc(alloc), _root_ptr(nullptr)
    {
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Alloc>
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(comp), _alloc(alloc), _root_ptr(nullptr)
    {
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Iterator>
    void
        interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::_fill_construct(
            Iterator itr,
            Iterator itr_end
        )
    {
        typedef ::std::tuple<size_type,size_type,size_type,bool,bool> IndexTuple;
        size_type one = ::boost::initialized_value;
        ++one;

        if (itr + one < itr_end)
        {
            size_type index_h = itr_end - itr - one;
            size_type index_m = index_h >> one;
            size_type index_l = ::boost::initialized_value;
            ::odds_and_ends::node::container::queue<_node_ptr_t,Size,AllocXForm> n_q;
            _node_ptr_t node_ptr = (
                ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1)
            );

            ::std::allocator_traits<allocator_type>::construct(
                this->_alloc,
                node_ptr,
                interval_type(*(itr + index_m), *(itr + index_m + one)),
                mapped_type()
            );
            this->_root_ptr = node_ptr;

            _node_ptr_t curr_ptr = node_ptr;
            ::odds_and_ends::node::container::queue<IndexTuple,Size,AllocXForm> i_q;

            if (index_l < index_m)
            {
                if (index_m + one < index_h)
                {
                    i_q.push(
                        IndexTuple(index_l, (index_l + index_m) >> one, index_m, true, false)
                    );
                    i_q.push(
                        IndexTuple(
                            index_m + one,
                            (index_m + index_h + one) >> one,
                            index_h,
                            false,
                            true
                        )
                    );
                }
                else
                {
                    i_q.push(IndexTuple(index_l, (index_l + index_m) >> one, index_m, true, true));
                }
            }
            else if (index_m + one < index_h)
            {
                i_q.push(
                    IndexTuple(
                        index_m + one,
                        (index_m + index_h + one) >> one,
                        index_h,
                        false,
                        true
                    )
                );
            }

            for (IndexTuple current_index; !i_q.empty(); )
            {
                current_index = i_q.front();
                i_q.pop();
                index_l = ::std::get<0>(current_index);
                index_m = ::std::get<1>(current_index);
                index_h = ::std::get<2>(current_index);
                node_ptr = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
                ::std::allocator_traits<allocator_type>::construct(
                    this->_alloc,
                    node_ptr,
                    interval_type(*(itr + index_m), *(itr + index_m + one)),
                    mapped_type()
                );
                n_q.push(node_ptr);

                if (::std::get<3>(current_index))
                {
                    curr_ptr->set_left_ptr(node_ptr);
                }
                else
                {
                    curr_ptr->set_right_ptr(node_ptr);
                }

                if (index_l < index_m)
                {
                    if (index_m + one < index_h)
                    {
                        i_q.push(
                            IndexTuple(index_l, (index_l + index_m) >> one, index_m, true, false)
                        );
                        i_q.push(
                            IndexTuple(
                                index_m + one,
                                (index_m + index_h + one) >> one,
                                index_h,
                                false,
                                true
                            )
                        );
                    }
                    else
                    {
                        i_q.push(
                            IndexTuple(index_l, (index_l + index_m) >> one, index_m, true, true)
                        );
                    }
                }
                else if (index_m + one < index_h)
                {
                    i_q.push(
                        IndexTuple(
                            index_m + one,
                            (index_m + index_h + one) >> one,
                            index_h,
                            false,
                            true
                        )
                    );
                }

                if (::std::get<4>(current_index))
                {
                    curr_ptr = n_q.front();
                    n_q.pop();
                }
            }

            Balancer::post_fill(*this->_root_ptr);
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Iterator>
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        Iterator itr_begin,
        Iterator itr_end,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_indexable_iterator<Iterator>,
            _enabler
        >::type
    ) : _comp(), _alloc(), _root_ptr(nullptr)
    {
        this->_fill_construct(itr_begin, itr_end);
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Iterator>
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        Iterator itr_begin,
        Iterator itr_end,
        key_compare const& comp,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_indexable_iterator<Iterator>,
            _enabler
        >::type
    ) : _comp(comp), _alloc(), _root_ptr(nullptr)
    {
        this->_fill_construct(itr_begin, itr_end);
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Iterator, typename Alloc>
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        Iterator itr_begin,
        Iterator itr_end,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept::is_indexable_iterator<Iterator>,
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(), _alloc(alloc), _root_ptr(nullptr)
    {
        this->_fill_construct(itr_begin, itr_end);
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Iterator, typename Alloc>
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        Iterator itr_begin,
        Iterator itr_end,
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept::is_indexable_iterator<Iterator>,
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(comp), _alloc(alloc), _root_ptr(nullptr)
    {
        this->_fill_construct(itr_begin, itr_end);
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Iterator>
    void
        interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::_copy_construct(
            Iterator itr,
            Iterator itr_end,
            size_type const& copy_size
        )
    {
        typedef ::std::tuple<size_type,size_type,size_type,bool,bool> IndexTuple;

        if (itr != itr_end)
        {
            size_type one = ::boost::initialized_value;
            ++one;
            size_type index_h = copy_size;
            size_type index_m = index_h >> one;
            size_type index_l = ::boost::initialized_value;
            ::odds_and_ends::node::container::queue<_node_ptr_t,Size,AllocXForm> n_q;
            _node_ptr_t node_ptr = (
                ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1)
            );

            ::std::allocator_traits<allocator_type>::construct(
                this->_alloc,
                node_ptr,
                (itr + index_m)->first,
                (itr + index_m)->second
            );
            this->_root_ptr = node_ptr;

            _node_ptr_t curr_ptr = node_ptr;
            ::odds_and_ends::node::container::queue<IndexTuple,Size,AllocXForm> i_q;

            if (index_l < index_m)
            {
                if (index_m + one < index_h)
                {
                    i_q.push(
                        IndexTuple(index_l, (index_l + index_m) >> one, index_m, true, false)
                    );
                    i_q.push(
                        IndexTuple(
                            index_m + one,
                            (index_m + index_h + one) >> one,
                            index_h,
                            false,
                            true
                        )
                    );
                }
                else
                {
                    i_q.push(IndexTuple(index_l, (index_l + index_m) >> one, index_m, true, true));
                }
            }
            else if (index_m + one < index_h)
            {
                i_q.push(
                    IndexTuple(
                        index_m + one,
                        (index_m + index_h + one) >> one,
                        index_h,
                        false,
                        true
                    )
                );
            }

            for (IndexTuple current_index; !i_q.empty(); )
            {
                current_index = i_q.front();
                i_q.pop();
                index_l = ::std::get<0>(current_index);
                index_m = ::std::get<1>(current_index);
                index_h = ::std::get<2>(current_index);
                node_ptr = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
                ::std::allocator_traits<allocator_type>::construct(
                    this->_alloc,
                    node_ptr,
                    (itr + index_m)->first,
                    (itr + index_m)->second
                );
                n_q.push(node_ptr);

                if (::std::get<3>(current_index))
                {
                    curr_ptr->set_left_ptr(node_ptr);
                }
                else
                {
                    curr_ptr->set_right_ptr(node_ptr);
                }

                if (index_l < index_m)
                {
                    if (index_m + one < index_h)
                    {
                        i_q.push(
                            IndexTuple(index_l, (index_l + index_m) >> one, index_m, true, false)
                        );
                        i_q.push(
                            IndexTuple(
                                index_m + one,
                                (index_m + index_h + one) >> one,
                                index_h,
                                false,
                                true
                            )
                        );
                    }
                    else
                    {
                        i_q.push(
                            IndexTuple(index_l, (index_l + index_m) >> one, index_m, true, true)
                        );
                    }
                }
                else if (index_m + one < index_h)
                {
                    i_q.push(
                        IndexTuple(
                            index_m + one,
                            (index_m + index_h + one) >> one,
                            index_h,
                            false,
                            true
                        )
                    );
                }

                if (::std::get<4>(current_index))
                {
                    curr_ptr = n_q.front();
                    n_q.pop();
                }
            }

            Balancer::post_fill(*this->_root_ptr);
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        interval_map const& copy
    ) : _comp(copy._comp), _alloc(copy._alloc), _root_ptr(nullptr)
    {
        this->_copy_construct(copy.cbegin(), copy.cend(), copy.size());
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        interval_map const& copy,
        key_compare const& comp
    ) : _comp(comp), _alloc(copy._alloc), _root_ptr(nullptr)
    {
        this->_copy_construct(copy.cbegin(), copy.cend(), copy.size());
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Alloc>
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        interval_map const& copy,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(copy._comp), _alloc(alloc), _root_ptr(nullptr)
    {
        this->_copy_construct(copy.cbegin(), copy.cend(), copy.size());
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Alloc>
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        interval_map const& copy,
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(comp), _alloc(alloc), _root_ptr(nullptr)
    {
        this->_copy_construct(copy.cbegin(), copy.cend(), copy.size());
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <
        typename K,
        typename M,
        typename N,
        typename B,
        typename C,
        typename S,
        typename P,
        typename A
    >
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        interval_map<K,M,N,B,C,S,P,A> const& copy,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<K,Key>,
                ::std::is_convertible<M,Mapped>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(copy._comp), _alloc(copy._alloc), _root_ptr(nullptr)
    {
        this->_copy_construct(copy.cbegin(), copy.cend(), copy.size());
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <
        typename K,
        typename M,
        typename N,
        typename B,
        typename C,
        typename S,
        typename P,
        typename A
    >
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        interval_map<K,M,N,B,C,S,P,A> const& copy,
        key_compare const& comp,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<K,Key>,
                ::std::is_convertible<M,Mapped>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(comp), _alloc(copy._alloc), _root_ptr(nullptr)
    {
        this->_copy_construct(copy.cbegin(), copy.cend(), copy.size());
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <
        typename K,
        typename M,
        typename N,
        typename B,
        typename C,
        typename S,
        typename P,
        typename A,
        typename Alloc
    >
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        interval_map<K,M,N,B,C,S,P,A> const& copy,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::if_<
                    ::std::is_convertible<K,Key>,
                    ::std::is_convertible<M,Mapped>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(copy._comp), _alloc(alloc), _root_ptr(nullptr)
    {
        this->_copy_construct(copy.cbegin(), copy.cend(), copy.size());
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <
        typename K,
        typename M,
        typename N,
        typename B,
        typename C,
        typename S,
        typename P,
        typename A,
        typename Alloc
    >
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        interval_map<K,M,N,B,C,S,P,A> const& copy,
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::if_<
                    ::std::is_convertible<K,Key>,
                    ::std::is_convertible<M,Mapped>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(comp), _alloc(alloc), _root_ptr(nullptr)
    {
        this->_copy_construct(copy.cbegin(), copy.cend(), copy.size());
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        interval_map&& source
    ) : _comp(source._comp), _alloc(source._alloc), _root_ptr(source._root_ptr)
    {
        source._root_ptr = nullptr;
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        interval_map&& source,
        key_compare const& comp
    ) : _comp(comp), _alloc(source._alloc), _root_ptr(source._root_ptr)
    {
        source._root_ptr = nullptr;
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Alloc>
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        interval_map&& source,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(source._comp), _alloc(alloc), _root_ptr(source._root_ptr)
    {
        source._root_ptr = nullptr;
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Alloc>
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::interval_map(
        interval_map&& source,
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(comp), _alloc(alloc), _root_ptr(source._root_ptr)
    {
        source._root_ptr = nullptr;
    }

    template <
        typename Key,
        typename M,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline void interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::clear()
    {
        if (this->_root_ptr)
        {
            for (
                ::odds_and_ends::node::post_order_tree_iterator<node_type> itr(*this->_root_ptr);
                !(!itr);
                ++itr
            )
            {
                if (itr->left())
                {
                    ::std::allocator_traits<allocator_type>::destroy(this->_alloc, itr->left());
                    ::std::allocator_traits<allocator_type>::deallocate(
                        this->_alloc,
                        itr->left(),
                        1
                    );
                }

                if (itr->right())
                {
                    ::std::allocator_traits<allocator_type>::destroy(this->_alloc, itr->right());
                    ::std::allocator_traits<allocator_type>::deallocate(
                        this->_alloc,
                        itr->right(),
                        1
                    );
                }
            }

            ::std::allocator_traits<allocator_type>::destroy(this->_alloc, this->_root_ptr);
            ::std::allocator_traits<allocator_type>::deallocate(this->_alloc, this->_root_ptr, 1);
            this->_root_ptr = nullptr;
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::~interval_map()
    {
        this->clear();
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>&
        interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::operator=(
            interval_map const& copy
        )
    {
        if (this != &copy)
        {
            this->clear();
            this->_comp = copy._comp;
            this->_copy_construct(copy.cbegin(), copy.cend(), copy.size());
        }

        return *this;
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>&
        interval_map<Key,Mapped,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::operator=(
            interval_map&& source
        )
    {
        if (this != &static_cast<interval_map&>(source))
        {
            this->clear();
            this->_comp = source._comp;
            this->_root_ptr = source._root_ptr;
            source._root_ptr = nullptr;
        }

        return *this;
    }

    template <
        typename Key,
        typename M,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::allocator_type
        interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::get_allocator() const
    {
        return this->_alloc;
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Balancer,
        typename Compare,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline bool
        interval_map<Key,Mapped,NPGList,Balancer,Compare,Size,PtrXForm,AllocXForm>::empty() const
    {
        return !this->_root_ptr;
    }

    template <
        typename Key,
        typename M,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename interval_map<Key,M,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::size_type
        interval_map<Key,M,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::size() const
    {
        return this->_root_ptr ? this->_root_ptr->size() : ::boost::initialized_value;
    }

    template <
        typename Key,
        typename M,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::const_iterator
        interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::cbegin() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_begin(*this->_root_ptr)
        ) : this->cend();
    }

    template <
        typename Key,
        typename M,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::const_iterator
        interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::begin() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_begin(*this->_root_ptr)
        ) : this->end();
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename interval_map<Key,Mapped,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::iterator
        interval_map<Key,Mapped,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::begin()
    {
        return this->_root_ptr ? iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_begin(*this->_root_ptr)
        ) : this->end();
    }

    template <
        typename Key,
        typename M,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::const_iterator
        interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::cend() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_end(*this->_root_ptr)
        ) : const_iterator();
    }

    template <
        typename Key,
        typename M,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::const_iterator
        interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::end() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_end(*this->_root_ptr)
        ) : const_iterator();
    }

    template <
        typename Key,
        typename Mapped,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename interval_map<Key,Mapped,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::iterator
        interval_map<Key,Mapped,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::end()
    {
        return this->_root_ptr ? iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_end(*this->_root_ptr)
        ) : iterator();
    }

    template <
        typename K,
        typename M,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXF,
        typename AllocXF
    >
    inline typename interval_map<K,M,NPGList,Bal,Comp,Size,PtrXF,AllocXF>::const_reverse_iterator
        interval_map<K,M,NPGList,Bal,Comp,Size,PtrXF,AllocXF>::crbegin() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_begin(*this->_root_ptr)
        ) : this->crend();
    }

    template <
        typename K,
        typename M,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXF,
        typename AllocXF
    >
    inline typename interval_map<K,M,NPGList,Bal,Comp,Size,PtrXF,AllocXF>::const_reverse_iterator
        interval_map<K,M,NPGList,Bal,Comp,Size,PtrXF,AllocXF>::rbegin() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_begin(*this->_root_ptr)
        ) : this->rend();
    }

    template <
        typename K,
        typename M,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXF,
        typename AllocXF
    >
    inline typename interval_map<K,M,NPGList,Bal,Comp,Size,PtrXF,AllocXF>::reverse_iterator
        interval_map<K,M,NPGList,Bal,Comp,Size,PtrXF,AllocXF>::rbegin()
    {
        return this->_root_ptr ? reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_begin(*this->_root_ptr)
        ) : this->rend();
    }

    template <
        typename Key,
        typename M,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXF,
        typename AllocXF
    >
    inline typename interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXF,AllocXF>::const_reverse_iterator
        interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXF,AllocXF>::crend() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_end(*this->_root_ptr)
        ) : const_reverse_iterator();
    }

    template <
        typename Key,
        typename M,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXF,
        typename AllocXF
    >
    inline typename interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXF,AllocXF>::const_reverse_iterator
        interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXF,AllocXF>::rend() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_end(*this->_root_ptr)
        ) : const_reverse_iterator();
    }

    template <
        typename Key,
        typename M,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXF,
        typename AllocXF
    >
    inline typename interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXF,AllocXF>::reverse_iterator
        interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXF,AllocXF>::rend()
    {
        return this->_root_ptr ? reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_end(*this->_root_ptr)
        ) : reverse_iterator();
    }

    template <
        typename Key,
        typename M,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXF,
        typename AllocXF
    >
    inline typename interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXF,AllocXF>::const_iterator
        interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXF,AllocXF>::find(key_type const& key) const
    {
        _node_ptr_t node_ptr = (
            ::odds_and_ends::node::algorithm
            ::binary_tree_descendant(this->_root_ptr, key, value_compare(this->_comp))
        );
        return node_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position(*node_ptr)
        ) : this->cend();
    }

    template <
        typename Key,
        typename M,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::iterator
        interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::find(key_type const& key)
    {
        _node_ptr_t node_ptr = (
            ::odds_and_ends::node::algorithm
            ::binary_tree_descendant(this->_root_ptr, key, value_compare(this->_comp))
        );
        return node_ptr ? iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position(*node_ptr)
        ) : this->end();
    }

    template <
        typename Key,
        typename M,
        typename NPGList,
        typename Bal,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename K>
    inline typename interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::const_iterator
        interval_map<Key,M,NPGList,Bal,Comp,Size,PtrXForm,AllocXForm>::find(K const& k) const
    {
        _node_ptr_t node_ptr = (
            ::odds_and_ends::node::algorithm
            ::binary_tree_descendant(this->_root_ptr, k, value_compare(this->_comp))
        );
        return node_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position(*node_ptr)
        ) : this->cend();
    }

    template <
        typename Key,
        typename M,
        typename NPGList,
        typename Balancer,
        typename Comp,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename K>
    inline typename interval_map<Key,M,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::iterator
        interval_map<Key,M,NPGList,Balancer,Comp,Size,PtrXForm,AllocXForm>::find(K const& k)
    {
        _node_ptr_t node_ptr = (
            ::odds_and_ends::node::algorithm
            ::binary_tree_descendant(this->_root_ptr, k, value_compare(this->_comp))
        );
        return node_ptr ? iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position(*node_ptr)
        ) : this->end();
    }
}}}  // namespace odds_and_ends::node::container

#endif  // ODDS_AND_ENDS__NODE__CONTAINER__INTERVAL_MAP_HPP

