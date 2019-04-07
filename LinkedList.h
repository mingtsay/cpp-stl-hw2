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
        typename NodeWrapper<T>::iterator first;
    public:
        LinkedList();

        explicit LinkedList(typename NodeWrapper<T>::iterator);

        NodeWrapper<T> begin();

        NodeWrapper<T> end();

        typename NodeWrapper<T>::iterator insert(typename NodeWrapper<T>::iterator, T);

        typename NodeWrapper<T>::iterator erase(typename NodeWrapper<T>::iterator);

        bool empty();

        void printList();

        void printList(typename NodeWrapper<T>::iterator);
    };
}


#endif //CPP_STL_HW2_LINKEDLIST_H
