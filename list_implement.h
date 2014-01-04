#include <cstdlib>
#include "exception.h"
#include "list_node_implement.h"
#include "list_iterator_implement.h"

template <typename ContentsType>
List<ContentsType>::List() : firstNodePointer(NULL), lastNodePointer(NULL) {}

template <typename ContentsType>
List<ContentsType>::List(uint initSize) :   firstNodePointer(NULL),
                                            lastNodePointer(NULL) {
    for (int element = 1; element <= initSize; ++element) {
        push_front();
    }
}

template <typename ContentsType>
List<ContentsType>::List(uint elementsNumber, const ContentsType& _value) : firstNodePointer(NULL),
                                                                            lastNodePointer(NULL) {
    for (int element = 1; element <= elementsNumber; ++element) {
        push_front(_value);
    }
}

template <typename ContentsType>
List<ContentsType>::~List() {
    clear();
}

template <typename ContentsType>
ListIterator<ContentsType> List<ContentsType>::begin() const {
    ListIterator<ContentsType> iterator = ListIterator<ContentsType>(firstNodePointer);
    return iterator;
}

template <typename ContentsType>
ListIterator<ContentsType> List<ContentsType>::end() const {
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
void List<ContentsType>::push_front() {
    if (firstNodePointer == NULL) {
        firstNodePointer    = new ListNode<ContentsType>();
        lastNodePointer     = firstNodePointer;
    }
    else {
        ListNode<ContentsType>* newNode = new ListNode<ContentsType>();

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
void List<ContentsType>::push_back() {
    if (lastNodePointer == NULL) {
        lastNodePointer     = new ListNode<ContentsType>();
        firstNodePointer    = lastNodePointer;
    }
    else {
        ListNode<ContentsType>* newNode = new ListNode<ContentsType>();

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
    if (newFirstNodePointer != NULL) {
        newFirstNodePointer->previousNodePointer = NULL;
    }
}

template <typename ContentsType>
void List<ContentsType>::pop_back() {
    if (lastNodePointer == NULL) {
        throw Exception("Attempted to access non-exsistent node", __FILE__, __LINE__);
    }

    ListNode<ContentsType>* newLastNodePointer = lastNodePointer->previousNodePointer;
    delete lastNodePointer;
    rewriteLastNodePointer(newLastNodePointer);
    if (newLastNodePointer != NULL) {
        newLastNodePointer->nextNodePointer = NULL;
    }
}

template <typename ContentsType>
void List<ContentsType>::concat(List<ContentsType>& listToAdd) {
    ListNode<ContentsType>* listToAddFirstNode = listToAdd.getFirstNodePointer();
    ListNode<ContentsType>* listToAddLastNode = listToAdd.getLastNodePointer();

    if (listToAddFirstNode == NULL) {
        return;
    }

    ListNode<ContentsType>* baseListLastNode = this->getLastNodePointer();
    if (baseListLastNode == NULL) {
        this->rewriteFirstNodePointer(listToAddFirstNode);
    }
    else {
        baseListLastNode->nextNodePointer = listToAddFirstNode;
    }
    this->rewriteLastNodePointer(listToAddLastNode);

    listToAddFirstNode->previousNodePointer = baseListLastNode;
    listToAdd.rewriteFirstNodePointer(NULL);
    listToAdd.rewriteLastNodePointer(NULL);
}

template <typename ContentsType>
void List<ContentsType>::splice(ListIterator<ContentsType> iter, List<ContentsType>& listToAdd) {
    ListNode<ContentsType>* listToAddFirstNode = listToAdd.getFirstNodePointer();
    ListNode<ContentsType>* listToAddLastNode = listToAdd.getLastNodePointer();

    if (listToAddFirstNode == NULL) {
        return;
    }

    ListNode<ContentsType>* iterNodePointer = iter.myNodePointer;
    ListNode<ContentsType>* afterIterNodePointer = iterNodePointer->nextNodePointer;

    listToAddFirstNode->previousNodePointer = iterNodePointer;
    listToAddLastNode->nextNodePointer = afterIterNodePointer;

    iterNodePointer->nextNodePointer = listToAddFirstNode;
    if (afterIterNodePointer == NULL) {
        rewriteLastNodePointer(listToAddLastNode);
    }
    else {
        afterIterNodePointer->previousNodePointer = listToAddLastNode;
    }

    listToAdd.rewriteFirstNodePointer(NULL);
    listToAdd.rewriteLastNodePointer(NULL);
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
unsigned long int List<ContentsType>::size() const {
    ListNode<ContentsType>* nextNodePointer = firstNodePointer;
    unsigned long int counter = 0;

    while (nextNodePointer != NULL) {
        ++counter;
        nextNodePointer = nextNodePointer->nextNodePointer;
    }

    return counter;
}
