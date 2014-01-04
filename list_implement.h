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
List<ContentsType>::List(uint elementsNumber, const ContentsType& _value)
    : firstNodePointer(NULL)
    , lastNodePointer(NULL) {

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
    return ListIterator<ContentsType>(firstNodePointer);
}

template <typename ContentsType>
ListIterator<ContentsType> List<ContentsType>::end() const {
    return ListIterator<ContentsType>(lastNodePointer);
}

template <typename ContentsType>
ContentsType& List<ContentsType>::front() {
    if (empty() ) {
        throw Exception("Attempted to access non-exsistent node", __FILE__, __LINE__);
    }

    return firstNodePointer->value;
}

template <typename ContentsType>
const ContentsType& List<ContentsType>::front() const {
    if (empty() ) {
        throw Exception("Attempted to access non-exsistent node", __FILE__, __LINE__);
    }

    return firstNodePointer->value;
}

template <typename ContentsType>
ContentsType& List<ContentsType>::back() {
    if (empty() ) {
        throw Exception("Attempted to access non-exsistent node", __FILE__, __LINE__);
    }

    return lastNodePointer->value;
}

template <typename ContentsType>
const ContentsType& List<ContentsType>::back() const {
    if (empty() ) {
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
    insertNewNodeBeforeExistingNode(new ListNode<ContentsType>(_value),
                                    firstNodePointer);
}

template <typename ContentsType>
void List<ContentsType>::push_front() {
    insertNewNodeBeforeExistingNode(new ListNode<ContentsType>(),
                                    firstNodePointer);
}

template <typename ContentsType>
void List<ContentsType>::push_back(const ContentsType& _value) {
    ListNode<ContentsType>* END_OF_LIST = NULL;
    insertNewNodeBeforeExistingNode(new ListNode<ContentsType>(_value),
                                    END_OF_LIST);
}

template <typename ContentsType>
void List<ContentsType>::push_back() {
    ListNode<ContentsType>* END_OF_LIST = NULL;
    insertNewNodeBeforeExistingNode(new ListNode<ContentsType>(),
                                    END_OF_LIST);
}

template <typename ContentsType>
void List<ContentsType>::insertNewNodeBeforeExistingNode(ListNode<ContentsType>* newNode,
                                     ListNode<ContentsType>* existingNode) {
    ListNode<ContentsType>* END_OF_LIST = NULL;
    ListNode<ContentsType>* START_OF_LIST = NULL;

    if (empty() ) {
        rewriteFirstNodePointer(newNode);
        rewriteLastNodePointer(newNode);
    }
    else {
        ListNode<ContentsType>* previousNode;

        if (existingNode == END_OF_LIST) {
            previousNode = lastNodePointer;
            rewriteLastNodePointer(newNode);
        }
        else {
            previousNode = existingNode->previousNodePointer;
            existingNode->previousNodePointer = newNode;
        }

        if (previousNode == START_OF_LIST) {
            rewriteFirstNodePointer(newNode);
        }
        else {
            previousNode->nextNodePointer = newNode;
        }

        newNode->nextNodePointer = existingNode;
        newNode->previousNodePointer = previousNode;
    }
}

template <typename ContentsType>
void List<ContentsType>::pop_front() {
    if (empty() ) {
        throw Exception("Attempted to access non-exsistent node", __FILE__, __LINE__);
    }

    deleteNode(firstNodePointer);
}

template <typename ContentsType>
void List<ContentsType>::pop_back() {
    if (empty() ) {
        throw Exception("Attempted to access non-exsistent node", __FILE__, __LINE__);
    }

    deleteNode(lastNodePointer);
}

template <typename ContentsType>
void List<ContentsType>::deleteNode(ListNode<ContentsType>* nodeToDelete) {
    ListNode<ContentsType>* nextNodePointer     = nodeToDelete->nextNodePointer;
    ListNode<ContentsType>* previousNodePointer = nodeToDelete->previousNodePointer;

    delete nodeToDelete;

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
void List<ContentsType>::splice(const ListIterator<ContentsType>& iter, List<ContentsType>& listToAdd) {
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
ListIterator<ContentsType> List<ContentsType>::insert(const ListIterator<ContentsType>& iter,
                                                      const ContentsType& _value) {
    ListNode<ContentsType>* newNode = new ListNode<ContentsType>(_value);
    insertNewNodeBeforeExistingNode(newNode, iter.myNodePointer);

    return ListIterator<ContentsType>(newNode);
}

template <typename ContentsType>
ListIterator<ContentsType> List<ContentsType>::erase(const ListIterator<ContentsType>& iter) {
    ListNode<ContentsType>* nodeToPointForReturnedIter = iter.myNodePointer->nextNodePointer;

    if (iter == end() ) {
        nodeToPointForReturnedIter = lastNodePointer->previousNodePointer;
    }

    deleteNode(iter.myNodePointer);

    return ListIterator<ContentsType>(nodeToPointForReturnedIter);
}

template <typename ContentsType>
void List<ContentsType>::clear() {
    while (!empty() ) {
        deleteNode(firstNodePointer);
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
