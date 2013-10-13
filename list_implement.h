#include <cstdlib>
#include "list.h"

/************************************************
 * Node implementation
 ***********************************************/

template <typename ContentsType>
ListNode<ContentsType>::ListNode() : nextNodePointer(NULL), previousNodePointer(NULL) {}

template <typename ContentsType>
ListNode<ContentsType>::ListNode(const ContentsType& _value) :  value(_value)
                                                                ,nextNodePointer(NULL)
                                                                ,previousNodePointer(NULL) {}

template <typename ContentsType>
ContentsType* ListNode<ContentsType>::getValuePointer() const {
    return &value;
}

template <typename ContentsType>
ListNode<ContentsType>* ListNode<ContentsType>::getNextNodePointer() const {
    return nextNodePointer;
}

template <typename ContentsType>
ListNode<ContentsType>* ListNode<ContentsType>::getPreviousNodePointer() const {
    return previousNodePointer;
}

template <typename ContentsType>
void ListNode<ContentsType>::rewriteNextNodePointer(const ListNode<ContentsType>* nodePointer) {
    nextNodePointer = nodePointer;
}

template <typename ContentsType>
void ListNode<ContentsType>::rewritePreviousNodePointer(const ListNode<ContentsType>* nodePointer) {
    previousNodePointer = nodePointer;
}

/************************************************
 *  List implementation
 ***********************************************/

template <typename ContentsType>
List<ContentsType>::List() : firstNodePointer(NULL), lastNodePointer(NULL) {}

template <typename ContentsType>
List<ContentsType>::List(const ContentsType& _value) {}

template <typename ContentsType>
List<ContentsType>::List(int elementsNumber, const ContentsType& _value) {}

template <typename ContentsType>
void List<ContentsType>::push_front(const ContentsType& _value) {
    if (firstNodePointer == NULL) {
        firstNodePointer    = new ListNode<ContentsType>(_value);
        lastNodePointer     = firstNodePointer;
    }
    else {
        ListNode<ContentsType>* newNode = new ListNode<ContentsType>(_value);

        newNode->rewriteNextNodePointer(firstNodePointer);

        firstNodePointer->rewritePreviousNodePointer(newNode);

        rewriteFirstNodePointer(newNode);
    }
}

template <typename ContentsType>
void List<ContentsType>::push_back(const ContentsType& _value) {
    if (lastNodePointer == NULL) {
        lastNodePointer     = new ListNode<ContentsType>(_value);
        firstNodePointer    = lastNodePointer;
    }
    else {
        ListNode<ContentsType>* newNode = new ListNode<ContentsType>(_value);

        newNode->rewritePreviousNodePointer(lastNodePointer);

        lastNodePointer->rewriteNextNodePointer(newNode);

        rewriteLastNodePointer(newNode);
    }
}
