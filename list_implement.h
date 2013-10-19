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

/************************************************
 *  Iterator implementation
 ***********************************************/

template <typename ContentsType>
ListIterator<ContentsType>::ListIterator(ListNode<ContentsType>* nodePointer) : myNodePointer(nodePointer) {
    if (nodePointer == NULL) {
        throw 2;
    }
}

template <typename ContentsType>
ListIterator<ContentsType> ListIterator<ContentsType>::operator+(int steps) {
    ListNode<ContentsType>* temp = myNodePointer;

    for (; steps > 0; --steps) {

        temp = temp->getNextNodePointer();

        if (temp == NULL) {
            throw 0;
        }
    }

    // myNodePointer = temp;
    return ListIterator<ContentsType>(temp);
}

template <typename ContentsType>
ListIterator<ContentsType> ListIterator<ContentsType>::operator-(int steps) {
    ListNode<ContentsType>* temp = myNodePointer;

    for (; steps > 0; --steps) {

        temp = temp->getPreviousNodePointer();

        if (temp == NULL) {
            throw 0;
        }
    }

    // myNodePointer = temp;
    return ListIterator<ContentsType>(temp);
}

template <typename ContentsType> // postfix operator
ListIterator<ContentsType> ListIterator<ContentsType>::operator++(int i) {
    ListNode<ContentsType>* temp = myNodePointer->getNextNodePointer();

    if (temp == NULL) {
        throw 0;
    }

    myNodePointer = temp;
    return *this;
}

template <typename ContentsType> // postfix operator
ListIterator<ContentsType> ListIterator<ContentsType>::operator--(int i) {
    ListNode<ContentsType>* temp = myNodePointer->getPreviousNodePointer();

    if (temp == NULL) {
        throw 0;
    }

    myNodePointer = temp;
    return *this;
}

template <typename ContentsType> // prefix operator
ListIterator<ContentsType> ListIterator<ContentsType>::operator++() {
    ListNode<ContentsType>* temp = myNodePointer->getNextNodePointer();

        if (temp == NULL) {
            throw 0;
        }

    myNodePointer = temp;
    return *this;
}

template <typename ContentsType> // prefix operator
ListIterator<ContentsType> ListIterator<ContentsType>::operator--() {
    ListNode<ContentsType>* temp = myNodePointer->getPreviousNodePointer();

    if (temp == NULL) {
        throw 0;
    }

    myNodePointer = temp;
    return *this;
}

template <typename ContentsType>
ContentsType ListIterator<ContentsType>::getNodeValue() const {
    return myNodePointer->getValue();
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
List<ContentsType>::~List() {
    if (firstNodePointer != NULL) {
        ListNode<ContentsType>* nodeToDelete = firstNodePointer;
        ListNode<ContentsType>* nextNodeToDelete = firstNodePointer->getNextNodePointer();

        while (nextNodeToDelete != NULL) {
            delete nodeToDelete;
            nodeToDelete = nextNodeToDelete;
            nextNodeToDelete = nextNodeToDelete->getNextNodePointer();
        }

        delete lastNodePointer;
    }
}

template <typename ContentsType>
ListIterator<ContentsType> List<ContentsType>::begin() {
    ListIterator<ContentsType> iterator = ListIterator<ContentsType>(firstNodePointer);
    return iterator;
}

template <typename ContentsType>
ListIterator<ContentsType> List<ContentsType>::end() {
    ListIterator<ContentsType> iterator = ListIterator<ContentsType>(lastNodePointer);
    return iterator;
}

template <typename ContentsType>
ContentsType List<ContentsType>::front() {
    // TODO: try-catch
    return firstNodePointer->getValue();
}

template <typename ContentsType>
ContentsType List<ContentsType>::back() {
    // TODO: try-catch
    return lastNodePointer->getValue();
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

template <typename ContentsType>
void List<ContentsType>::pop_front() {
    if (firstNodePointer == NULL) {
        throw 1;
    }

    ListNode<ContentsType>* newFirstNodePointer = firstNodePointer->getNextNodePointer();
    delete firstNodePointer;
    rewriteFirstNodePointer(newFirstNodePointer);
    newFirstNodePointer->rewritePreviousNodePointer(NULL);
}

template <typename ContentsType>
void List<ContentsType>::pop_back() {
    if (lastNodePointer == NULL) {
        throw 1;
    }

    ListNode<ContentsType>* newLastNodePointer = lastNodePointer->getPreviousNodePointer();
    delete lastNodePointer;
    rewriteLastNodePointer(newLastNodePointer);
    newLastNodePointer->rewriteNextNodePointer(NULL);
}

template <typename ContentsType>
long int List<ContentsType>::size() const {
    ListNode<ContentsType>* nextNodePointer = firstNodePointer;
    long int counter = 0;

    while (nextNodePointer != NULL) {
        ++counter;
        nextNodePointer = nextNodePointer->getNextNodePointer();
    }

    return counter;
}
