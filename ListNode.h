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

        Ptr ptr();

        Ptr nextNode();

        Ptr insert(T);

        Ptr erase(Ptr);
    };

    template<typename T>
    ListNode<T>::ListNode(T data, Ptr next): data(data), next(next) {}

    template<typename T>
    T ListNode<T>::operator()() const {
        return data;
    }

    template<typename T>
    typename ListNode<T>::Ptr ListNode<T>::ptr() {
        return this;
    }

    template<typename T>
    typename ListNode<T>::Ptr ListNode<T>::nextNode() {
        return next;
    }

    template<typename T>
    typename ListNode<T>::Ptr ListNode<T>::insert(T data) {
        return new ListNode<T>(data, this);
    }

    template<typename T>
    typename ListNode<T>::Ptr ListNode<T>::erase(Ptr first) {
        if (first != this)
            for (auto it = first; it->next != nullptr;) {
                if (it->next == this) {
                    return it->next = next;
                }
            }
        return next;
    }
}


#endif //CPP_STL_HW2_LISTNODE_H
