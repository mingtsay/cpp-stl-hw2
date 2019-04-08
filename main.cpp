#include <iostream>
#include <algorithm>
#include "LinkedList.h"

int main() {
    std::cout << "Initialize list." << std::endl;

    hw2::ListNode<int> list1(15), list2(10, &list1);
    hw2::NodeWrapper<int> wrapper(&list2);
    hw2::LinkedList<int> linkedList(wrapper);

    linkedList.printList();

    std::cout << std::endl;

    std::cout << "Insert 5 in front of the list." << std::endl;

    linkedList.insert(linkedList.begin(), 5);
    linkedList.printList();

    std::cout << std::endl;

    std::cout << "Find 20 in the list." << std::endl;

    auto pos = std::find(linkedList.begin(), linkedList.end(), 20);
    if (pos != linkedList.end()) {
        std::cout << "Found: " << *pos << std::endl;
    } else {
        std::cout << "Not Found." << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Find 10 in the list." << std::endl;

    pos = std::find(linkedList.begin(), linkedList.end(), 10);
    if (pos != linkedList.end()) {
        std::cout << "Found: " << *pos << std::endl; // expecting this
    } else {
        std::cout << "Not Found." << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Erase it from the list." << std::endl;

    linkedList.erase(pos);
    linkedList.printList();

    return 0;
}
