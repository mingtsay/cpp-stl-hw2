//
// Created by 藤原ツバサ on 2019-04-07.
//

#ifndef CPP_STL_HW2_LISTNODE_H
#define CPP_STL_HW2_LISTNODE_H

#include <cstdio>

namespace hw2 {

    template<typename T>
    class ListNode {
    public:
        typedef ListNode *Ptr;

    private:
        T data;
        Ptr next = nullptr;

    public:
        ListNode(T = static_cast<T>(0), Ptr = nullptr); // NOLINT(google-explicit-constructor)

        T operator()() const;

        Ptr nextNode();

        Ptr append(T);
    };

    template<typename T>
    ListNode<T>::ListNode(T, ListNode::Ptr): data(data), next(next) {}

    template<typename T>
    T ListNode<T>::operator()() const {
        return data;
    }

    template<typename T>
    typename ListNode<T>::Ptr ListNode<T>::nextNode() {
        return next;
    }

    template<typename T>
    typename ListNode<T>::Ptr ListNode<T>::append(T) {
        return next = new ListNode<T>(data, next);
    }
}


#endif //CPP_STL_HW2_LISTNODE_H
