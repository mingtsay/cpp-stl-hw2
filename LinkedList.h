//
// Created by 藤原ツバサ on 2019-04-07.
//

#ifndef CPP_STL_HW2_LINKEDLIST_H
#define CPP_STL_HW2_LINKEDLIST_H

#include "ListNode.h"
#include "NodeWrapper.h"

namespace hw2 {
    template<typename T>
    class LinkedList {
    private:
        typename NodeWrapper<T>::iterator &first;
    public:
        LinkedList();

        explicit LinkedList(typename NodeWrapper<T>::iterator &);

        typename NodeWrapper<T>::iterator begin();

        typename NodeWrapper<T>::iterator end();

        typename NodeWrapper<T>::iterator insert(typename NodeWrapper<T>::const_iterator, T &&);

        typename NodeWrapper<T>::iterator erase(typename NodeWrapper<T>::const_iterator);

        bool empty();

        void printList();

        void printList(typename NodeWrapper<T>::const_iterator, typename NodeWrapper<T>::const_iterator);
    };

    template<typename T>
    LinkedList<T>::LinkedList(): first(*(new NodeWrapper<T>())) {}

    template<typename T>
    LinkedList<T>::LinkedList(typename NodeWrapper<T>::iterator &it): first(it) {}

    template<typename T>
    typename NodeWrapper<T>::iterator LinkedList<T>::begin() {
        return *(new NodeWrapper<T>(first->ptr()));
    }

    template<typename T>
    typename NodeWrapper<T>::iterator LinkedList<T>::end() {
        return *(new NodeWrapper<T>());
    }

    template<typename T>
    typename NodeWrapper<T>::iterator LinkedList<T>::insert(typename NodeWrapper<T>::const_iterator wrapper, T &&data) {
        if (empty()) return first = *(new NodeWrapper<T>(new ListNode<T>(data)));
        if (first == wrapper) return first = *(new NodeWrapper<T>(begin()->insert(data)));
        return *(new NodeWrapper<T>(begin()->insert(data)));
    }

    template<typename T>
    typename NodeWrapper<T>::iterator LinkedList<T>::erase(typename NodeWrapper<T>::const_iterator wrapper) {
        if (first == wrapper) return first = *(new NodeWrapper<T>(wrapper->erase(first->ptr())));
        return *(new NodeWrapper<T>(wrapper->erase(first->ptr())));
    }

    template<typename T>
    bool LinkedList<T>::empty() {
        return begin() == end();
    }

    template<typename T>
    void LinkedList<T>::printList() {
        printList(begin(), end());
    }

    template<typename T>
    void LinkedList<T>::printList(typename NodeWrapper<T>::const_iterator head,
                                  typename NodeWrapper<T>::const_iterator tail) {
        for (auto it = head; it != tail;) {
            std::cout << *it;
            if (++it != end()) std::cout << ", ";
        }
        std::cout << std::endl;
    }
}


#endif //CPP_STL_HW2_LINKEDLIST_H
