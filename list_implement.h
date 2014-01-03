#include <cstdlib>
#include "exception.h"

/************************************************
 * Node implementation
 ***********************************************/

template <typename ContentsType>
ListNode<ContentsType>::ListNode() : nextNodePointer(NULL), previousNodePointer(NULL) {}

template <typename ContentsType>
ListNode<ContentsType>::ListNode(const ContentsType& _value) :  value(_value),
                                                                nextNodePointer(NULL),
                                                                previousNodePointer(NULL) {}

/************************************************
 *  Iterator implementation
 ***********************************************/

template <typename ContentsType>
ListIterator<ContentsType>::ListIterator(ListNode<ContentsType>* nodePointer) : myNodePointer(nodePointer) {
    if (nodePointer == NULL) {
        throw Exception("Attempted to go outside the list", __FILE__, __LINE__);
    }
}

template <typename ContentsType> // postfix operator
const ListIterator<ContentsType>& ListIterator<ContentsType>::operator++(int i) {
    ListNode<ContentsType>* temp = myNodePointer->nextNodePointer;

    if (temp == NULL) {
        throw Exception("Attempted to go outside the list", __FILE__, __LINE__);
    }

    myNodePointer = temp;
    return *this;
}

template <typename ContentsType> // postfix operator
const ListIterator<ContentsType>& ListIterator<ContentsType>::operator--(int i) {
    ListNode<ContentsType>* temp = myNodePointer->previousNodePointer;

    if (temp == NULL) {
        throw Exception("Attempted to go outside the list", __FILE__, __LINE__);
    }

    myNodePointer = temp;
    return *this;
}

template <typename ContentsType> // prefix operator
const ListIterator<ContentsType>& ListIterator<ContentsType>::operator++() {
    ListNode<ContentsType>* temp = myNodePointer->nextNodePointer;

    if (temp == NULL) {
        throw Exception("Attempted to go outside the list", __FILE__, __LINE__);
    }

    myNodePointer = temp;
    return *this;
}

template <typename ContentsType> // prefix operator
const ListIterator<ContentsType>& ListIterator<ContentsType>::operator--() {
    ListNode<ContentsType>* temp = myNodePointer->previousNodePointer;

    if (temp == NULL) {
        throw Exception("Attempted to go outside the list", __FILE__, __LINE__);
    }

    myNodePointer = temp;
    return *this;
}

template <typename ContentsType>
const ContentsType& ListIterator<ContentsType>::operator*() {
    return myNodePointer->value;
}

template <typename ContentsType>
void ListIterator<ContentsType>::rewriteNodePointer(ListNode<ContentsType>* pointer) {
    if (pointer == NULL) {
        throw Exception("Attempted to get iterator pointing to NULL", __FILE__, __LINE__);
    }

    myNodePointer = pointer;
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
    clear();
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
    if (firstNodePointer == NULL) {
        throw Exception("Attempted to access non-exsistent node", __FILE__, __LINE__);
    }

    return firstNodePointer->value;
}

template <typename ContentsType>
ContentsType List<ContentsType>::back() {
    if (lastNodePointer == NULL) {
        throw Exception("Attempted to access non-exsistent node", __FILE__, __LINE__);
    }

    return lastNodePointer->value;
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

        newNode->nextNodePointer = firstNodePointer;

        firstNodePointer->previousNodePointer = newNode;

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

        newNode->previousNodePointer = lastNodePointer;

        lastNodePointer->nextNodePointer = newNode;

        rewriteLastNodePointer(newNode);
    }
}

template <typename ContentsType>
void List<ContentsType>::pop_front() {
    if (firstNodePointer == NULL) {
        throw Exception("Attempted to access non-exsistent node", __FILE__, __LINE__);
    }

    ListNode<ContentsType>* newFirstNodePointer = firstNodePointer->nextNodePointer;
    delete firstNodePointer;
    rewriteFirstNodePointer(newFirstNodePointer);
    newFirstNodePointer->previousNodePointer = NULL;
}

template <typename ContentsType>
void List<ContentsType>::pop_back() {
    if (lastNodePointer == NULL) {
        throw Exception("Attempted to access non-exsistent node", __FILE__, __LINE__);
    }

    ListNode<ContentsType>* newLastNodePointer = lastNodePointer->previousNodePointer;
    delete lastNodePointer;
    rewriteLastNodePointer(newLastNodePointer);
    newLastNodePointer->nextNodePointer = NULL;
}

template <typename ContentsType>
void List<ContentsType>::concat(List<ContentsType>& addedList) {
    ListNode<ContentsType>* addedListFirstNode = addedList.getFirstNodePointer();
    ListNode<ContentsType>* addedListLastNode = addedList.getLastNodePointer();

    if (addedListFirstNode == NULL) {
        return;
    }

    ListNode<ContentsType>* baseListLastNode = this->getLastNodePointer();
    if (baseListLastNode == NULL) {
        this->rewriteFirstNodePointer(addedListFirstNode);
    }
    else {
        baseListLastNode->nextNodePointer = addedListFirstNode;
    }
    this->rewriteLastNodePointer(addedListLastNode);

    addedListFirstNode->previousNodePointer = baseListLastNode;
    addedList.rewriteFirstNodePointer(NULL);
    addedList.rewriteLastNodePointer(NULL);
}

template <typename ContentsType>
void List<ContentsType>::splice(ListIterator<ContentsType> iter, List<ContentsType>& addedList) {
    ListNode<ContentsType>* addedListFirstNode = addedList.getFirstNodePointer();
    ListNode<ContentsType>* addedListLastNode = addedList.getLastNodePointer();

    if (addedListFirstNode == NULL) {
        return;
    }

    ListNode<ContentsType>* iterNodePointer = iter.myNodePointer;
    ListNode<ContentsType>* afterIterNodePointer = iterNodePointer->nextNodePointer;

    addedListFirstNode->previousNodePointer = iterNodePointer;
    addedListLastNode->nextNodePointer = afterIterNodePointer;

    iterNodePointer->nextNodePointer = addedListFirstNode;
    if (afterIterNodePointer == NULL) {
        rewriteLastNodePointer(addedListLastNode);
    }
    else {
        afterIterNodePointer->previousNodePointer = addedListLastNode;
    }

    addedList.rewriteFirstNodePointer(NULL);
    addedList.rewriteLastNodePointer(NULL);
}

template <typename ContentsType>
bool List<ContentsType>::empty() const {
    return (firstNodePointer == NULL) && (lastNodePointer == NULL);
}

template <typename ContentsType>
ListIterator<ContentsType> List<ContentsType>::insert(ListIterator<ContentsType> iter,
                                                      const ContentsType& _value) {
    ListNode<ContentsType>* iteratorNodePointer = iter.myNodePointer;
    ListNode<ContentsType>* previousNodePointer = iteratorNodePointer->previousNodePointer;

    ListNode<ContentsType>* newNode = new ListNode<ContentsType>(_value);
    newNode->nextNodePointer = iteratorNodePointer;
    newNode->previousNodePointer = previousNodePointer;

    iteratorNodePointer->previousNodePointer = newNode;

    if (previousNodePointer == NULL) {
        rewriteFirstNodePointer(newNode);
    }
    else {
        previousNodePointer->nextNodePointer = newNode;
    }

    return ListIterator<ContentsType>(newNode);
}

template <typename ContentsType>
ListIterator<ContentsType> List<ContentsType>::erase(ListIterator<ContentsType> iter) {
    ListNode<ContentsType>* iteratorNodePointer = iter.myNodePointer;
    ListNode<ContentsType>* nextNodePointer     = iteratorNodePointer->nextNodePointer;
    ListNode<ContentsType>* previousNodePointer = iteratorNodePointer->previousNodePointer;

    delete iteratorNodePointer;

    if (previousNodePointer != NULL) {
        previousNodePointer->nextNodePointer = nextNodePointer;
    }
    else {
        rewriteFirstNodePointer(nextNodePointer);
    }

    if (nextNodePointer != NULL) {
        nextNodePointer->previousNodePointer = previousNodePointer;
    }
    else {
        rewriteLastNodePointer(previousNodePointer);

        // returns iterator for the end of the list
        // if the last element was deleted
        return ListIterator<ContentsType>(previousNodePointer);
    }

    // iter.rewriteNodePointer(nextNodePointer);
    return ListIterator<ContentsType>(nextNodePointer);
}

template <typename ContentsType>
void List<ContentsType>::clear() {
    if (firstNodePointer != NULL) {
        ListNode<ContentsType>* nodeToDelete = firstNodePointer;
        ListNode<ContentsType>* nextNodeToDelete = firstNodePointer->nextNodePointer;

        while (nextNodeToDelete != NULL) {
            delete nodeToDelete;
            nodeToDelete = nextNodeToDelete;
            nextNodeToDelete = nextNodeToDelete->nextNodePointer;
        }

        delete lastNodePointer;

        rewriteFirstNodePointer(NULL);
        rewriteLastNodePointer(NULL);
    }
}

template <typename ContentsType>
long int List<ContentsType>::size() const {
    ListNode<ContentsType>* nextNodePointer = firstNodePointer;
    long int counter = 0;

    while (nextNodePointer != NULL) {
        ++counter;
        nextNodePointer = nextNodePointer->nextNodePointer;
    }

    return counter;
}
