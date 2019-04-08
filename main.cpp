#include <iostream>
#include <algorithm>
#include "LinkedList.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    hw2::ListNode<int> list1(15), list2(10, &list1);
    hw2::NodeWrapper<int> wrapper(&list2);
    hw2::LinkedList<int> linkedList(wrapper);

    linkedList.printList();
    linkedList.insert(linkedList.begin(), 5);
    linkedList.printList();
    auto pos = std::find<hw2::NodeWrapper<int>::iterator &, int>(linkedList.begin(), linkedList.end(), 10);
    linkedList.erase(pos);
    linkedList.printList();

    return 0;
}
