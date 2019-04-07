//
// Created by 藤原ツバサ on 2019-04-07.
//

#ifndef CPP_STL_HW2_NODEWRAPPER_H
#define CPP_STL_HW2_NODEWRAPPER_H

#include <algorithm>
#include "ListNode.h"

namespace hw2 {
    template<typename T, typename Pointer, typename Reference>
    class NodeWrapperBase : public std::iterator<std::input_iterator_tag, T, ptrdiff_t, Pointer, Reference> {
    private:
        typename ListNode<T>::Ptr node;
    public:
        typedef NodeWrapperBase<T, T *, T &> iterator;
        typedef NodeWrapperBase<T, const T *, const T &> const_iterator;

        NodeWrapperBase(ListNode<T> * = nullptr); // NOLINT(google-explicit-constructor)

        NodeWrapperBase(iterator &); // NOLINT(google-explicit-constructor)

        NodeWrapperBase(const_iterator &); // NOLINT(google-explicit-constructor)

        T operator*();

        typename hw2::ListNode<T>::Ptr operator->();

        NodeWrapperBase &operator++();

        bool operator==(const NodeWrapperBase &) const;

        bool operator!=(const NodeWrapperBase &) const;
    };

    template<typename T>
    class NodeWrapper : public NodeWrapperBase<T, T *, T &> {
    public:
        explicit NodeWrapper(typename ListNode<T>::Ptr = nullptr);

        NodeWrapper(NodeWrapper<T> &);
    };
}


#endif //CPP_STL_HW2_NODEWRAPPER_H
