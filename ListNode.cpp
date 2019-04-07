//
// Created by 藤原ツバサ on 2019-04-07.
//

#include "ListNode.h"

template<typename T>
hw2::ListNode<T>::ListNode(T data, Ptr next) : data(data), next(next) {}

template<typename T>
T hw2::ListNode<T>::operator()() const {
    return data;
}

template<typename T>
typename hw2::ListNode<T>::Ptr hw2::ListNode<T>::nextNode() {
    return next;
}

template<typename T>
typename hw2::ListNode<T>::Ptr hw2::ListNode<T>::append(T data) {
    return next = new ListNode<T>(data, next);
}
