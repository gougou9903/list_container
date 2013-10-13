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
ContentsType ListNode<ContentsType>::getValue() const {
    return value;
}

template <typename ContentsType>
ListNode<ContentsType>* ListNode<ContentsType>::getNextNodePointer() {
    return nextNodePointer;
}

template <typename ContentsType>
ListNode<ContentsType>* ListNode<ContentsType>::getPreviousNodePointer() {
    return previousNodePointer;
}

template <typename ContentsType>
void ListNode<ContentsType>::rewriteNextNodePointer(ListNode<ContentsType>* nodePointer) {
    nextNodePointer = nodePointer;
}

template <typename ContentsType>
void ListNode<ContentsType>::rewritePreviousNodePointer(ListNode<ContentsType>* nodePointer) {
    previousNodePointer = nodePointer;
}

template <typename ContentsType>
ListNode<ContentsType>* List<ContentsType>::operator+(int steps) {
    if steps > 0 {
        ListNode<ContentsType>* wantedNode = nextNodePointer;
    }
}

/************************************************
 *  List implementation
 ***********************************************/

template <typename ContentsType>
List<ContentsType>::List() : firstNodePointer(NULL), lastNodePointer(NULL) {}

template <typename ContentsType>
List<ContentsType>::List(const ContentsType& _value) {
    firstNodePointer    = new ListNode<ContentsType>(_value);
    lastNodePointer     = firstNodePointer;
}

template <typename ContentsType>
List<ContentsType>::List(int elementsNumber, const ContentsType& _value) {
    firstNodePointer    = new ListNode<ContentsType>(_value);
    lastNodePointer     = firstNodePointer;

    for (int element = 1; element <= elementsNumber; ++element) {
        push_front(_value);
    }
}

template <typename ContentsType>
ListNode<ContentsType>* List<ContentsType>::getFirstNodePointer() {
    return firstNodePointer;
}

template <typename ContentsType>
ListNode<ContentsType>* List<ContentsType>::getLastNodePointer() {
    return lastNodePointer;
}

template <typename ContentsType>
void List<ContentsType>::rewriteFirstNodePointer(ListNode<ContentsType>* newNode) {
    firstNodePointer = newNode;
}

template <typename ContentsType>
void List<ContentsType>::rewriteLastNodePointer(ListNode<ContentsType>* newNode) {
    lastNodePointer = newNode;
}

template <typename ContentsType>
void List<ContentsType>::push_front(ContentsType& _value) {
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
void List<ContentsType>::push_back(ContentsType& _value) {
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
