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
void ListNode<ContentsType>::rewriteNextNodePointer(const ListNode<ContentsType>* nodePointer) {
    this->nextNodePointer = nodePointer;
}

template <typename ContentsType>
void ListNode<ContentsType>::rewritePreviousNodePointer(const ListNode<ContentsType>* nodePointer) {
    this->lastNodePointer = nodePointer;
}

/********************************************//**
 *  List implementation
 ***********************************************/

template <typename ContentsType>
List<ContentsType>::List() : firstNodePointer(NULL), lastNodePointer(NULL) {}

template <typename ContentsType>
List<ContentsType>::List(ContentsType _value) {}

template <typename ContentsType>
List<ContentsType>::List(int elementsNumber, ContentsType _value) {}

template <typename ContentsType>
void List<ContentsType>::push_front(ContentsType _value) {
    if (firstNodePointer == NULL) {
        firstNodePointer    = new ListNode<ContentsType>(_value);
        lastNodePointer     = firstNodePointer;
    }
    else {
        ListNode<ContentsType>* newNode = new ListNode<ContentsType>(_value);

        newNode->rewriteNextNodePointer(firstNodePointer);
        newNode->rewritePreviousNodePointer(lastNodePointer);

        this->firstNodePointer->rewritePreviousNodePointer(newNode);
        this->lastNodePointer->rewriteNextNodePointer(newNode);
        this->rewriteFirstNodePointer(newNode);
    }
}
