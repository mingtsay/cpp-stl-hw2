//
// Created by 藤原ツバサ on 2019-04-07.
//

#include "NodeWrapper.h"

template<typename T, typename Pointer, typename Reference>
hw2::NodeWrapperBase<T, Pointer, Reference>::NodeWrapperBase(ListNode<T> *ptr):node(ptr) {}

template<typename T, typename Pointer, typename Reference>
hw2::NodeWrapperBase<T, Pointer, Reference>::NodeWrapperBase(
        hw2::NodeWrapperBase<T, Pointer, Reference>::iterator &wrapper):node(wrapper.node) {}

template<typename T, typename Pointer, typename Reference>
hw2::NodeWrapperBase<T, Pointer, Reference>::NodeWrapperBase(
        hw2::NodeWrapperBase<T, Pointer, Reference>::const_iterator &wrapper):node(wrapper.node) {}

template<typename T, typename Pointer, typename Reference>
T hw2::NodeWrapperBase<T, Pointer, Reference>::operator*() {
    return node->operator()();
}

template<typename T, typename Pointer, typename Reference>
typename hw2::ListNode<T>::Ptr hw2::NodeWrapperBase<T, Pointer, Reference>::operator->() {
    return node;
}

template<typename T, typename Pointer, typename Reference>
hw2::NodeWrapperBase<T, Pointer, Reference> &hw2::NodeWrapperBase<T, Pointer, Reference>::operator++() {
    node = node->nextNode();
    return *this;
}

template<typename T, typename Pointer, typename Reference>
bool
hw2::NodeWrapperBase<T, Pointer, Reference>::operator==(
        const hw2::NodeWrapperBase<T, Pointer, Reference> &other) const {
    return node == other.node;
}

template<typename T, typename Pointer, typename Reference>
bool
hw2::NodeWrapperBase<T, Pointer, Reference>::operator!=(
        const hw2::NodeWrapperBase<T, Pointer, Reference> &other) const {
    return node != other.node;
}


template<typename T>
hw2::NodeWrapper<T>::NodeWrapper(typename ListNode<T>::Ptr ptr):NodeWrapperBase<T, T *, T &>(ptr) {}

template<typename T>
hw2::NodeWrapper<T>::NodeWrapper(NodeWrapper<T> &wrapper):NodeWrapperBase<T, T *, T &>(wrapper) {}
