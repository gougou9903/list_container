#include <cstdlib>
#include "list.h"

/********************************************//**
 * Node implementation
 ***********************************************/

template <typename ContentsType>
ListNode<ContentsType>::ListNode() : nextNodePointer(this), previousNodePointer(this) {}

template <typename ContentsType>
ListNode<ContentsType>::ListNode(const ContentsType& _value) :  value(_value)
                                                                ,nextNodePointer(this)
                                                                ,previousNodePointer(this) {}

template <typename ContentsType>
ContentsType* ListNode<ContentsType>::getValue() const {
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

/********************************************//**
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
        newNode->rewritePreviousNodePointer(lastNodePointer);

        firstNodePointer->rewritePreviousNodePointer(newNode);
        lastNodePointer->rewriteNextNodePointer(newNode);
        rewriteFirstNodePointer(newNode);
    }
}
