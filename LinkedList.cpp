//
// Created by 藤原ツバサ on 2019-04-07.
//

#include <iostream>
#include "LinkedList.h"

template<typename T>
hw2::LinkedList<T>::LinkedList():first(NodeWrapper<T>()) {}

template<typename T>
hw2::LinkedList<T>::LinkedList(typename NodeWrapper<T>::iterator it) :first(it) {}

template<typename T>
hw2::NodeWrapper<T> hw2::LinkedList<T>::begin() {
    return first;
}

template<typename T>
hw2::NodeWrapper<T> hw2::LinkedList<T>::end() {
    return NodeWrapper<T>();
}

template<typename T>
typename hw2::NodeWrapper<T>::iterator hw2::LinkedList<T>::insert(typename NodeWrapper<T>::iterator wrapper, T data) {
    if (empty()) return first = new NodeWrapper<T>(new ListNode<T>(data));
    return new NodeWrapper<T>(begin()->append(data));
}

template<typename T>
typename hw2::NodeWrapper<T>::iterator hw2::LinkedList<T>::erase(typename NodeWrapper<T>::iterator wrapper) {
    if (wrapper == first) {
        return first = nullptr;
    }
    typename NodeWrapper<T>::iterator next = wrapper;
    ++next;

    wrapper->data = next->data;
    wrapper->next = next->next;

    delete next;

    return wrapper;
}

template<typename T>
bool hw2::LinkedList<T>::empty() {
    return begin() == end();
}

template<typename T>
void hw2::LinkedList<T>::printList() {
    printList(begin());
}

template<typename T>
void hw2::LinkedList<T>::printList(typename NodeWrapper<T>::iterator first) {
    for (auto it = first; it != end(); ++it) {
        if (it != begin()) std::cout << ", ";
        std::cout << *it;
    }
    std::cout << std::endl;
}
