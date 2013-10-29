#include <cstdlib>
#include <string>
#include <sstream>

Exception::Exception(std::string _description,
                     std::string _fileName, int _line) : description(_description),
                                                         fileName(_fileName),
                                                         line(_line) {}

std::string Exception::getDescription() const {
    std::stringstream errorDesc;
    errorDesc << description << " at line " << line << " of the file " << fileName;
    return errorDesc.str();
}

/************************************************
 * Node implementation
 ***********************************************/

template <typename ContentsType>
ListNode<ContentsType>::ListNode() : nextNodePointer(NULL), previousNodePointer(NULL) {}

template <typename ContentsType>
ListNode<ContentsType>::ListNode(const ContentsType& _value) :  value(_value),
                                                                nextNodePointer(NULL),
                                                                previousNodePointer(NULL) {}

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
        throw Exception("Attempted to go outside the list", __FILE__, __LINE__);
    }
}

template <typename ContentsType>
ListIterator<ContentsType> ListIterator<ContentsType>::operator+(int steps) {
    ListNode<ContentsType>* temp = myNodePointer;

    for (; steps > 0; --steps) {

        temp = temp->getNextNodePointer();

        if (temp == NULL) {
            throw Exception("Attempted to go outside the list", __FILE__, __LINE__);
        }
    }

    return ListIterator<ContentsType>(temp);
}

template <typename ContentsType>
ListIterator<ContentsType> ListIterator<ContentsType>::operator-(int steps) {
    ListNode<ContentsType>* temp = myNodePointer;

    for (; steps > 0; --steps) {

        temp = temp->getPreviousNodePointer();

        if (temp == NULL) {
            throw Exception("Attempted to go outside the list", __FILE__, __LINE__);
        }
    }

    return ListIterator<ContentsType>(temp);
}

template <typename ContentsType> // postfix operator
ListIterator<ContentsType> ListIterator<ContentsType>::operator++(int i) {
    ListNode<ContentsType>* temp = myNodePointer->getNextNodePointer();

    if (temp == NULL) {
        throw Exception("Attempted to go outside the list", __FILE__, __LINE__);
    }

    myNodePointer = temp;
    return *this;
}

template <typename ContentsType> // postfix operator
ListIterator<ContentsType> ListIterator<ContentsType>::operator--(int i) {
    ListNode<ContentsType>* temp = myNodePointer->getPreviousNodePointer();

    if (temp == NULL) {
        throw Exception("Attempted to go outside the list", __FILE__, __LINE__);
    }

    myNodePointer = temp;
    return *this;
}

template <typename ContentsType> // prefix operator
ListIterator<ContentsType> ListIterator<ContentsType>::operator++() {
    ListNode<ContentsType>* temp = myNodePointer->getNextNodePointer();

        if (temp == NULL) {
            throw Exception("Attempted to go outside the list", __FILE__, __LINE__);
        }

    myNodePointer = temp;
    return *this;
}

template <typename ContentsType> // prefix operator
ListIterator<ContentsType> ListIterator<ContentsType>::operator--() {
    ListNode<ContentsType>* temp = myNodePointer->getPreviousNodePointer();

    if (temp == NULL) {
        throw Exception("Attempted to go outside the list", __FILE__, __LINE__);
    }

    myNodePointer = temp;
    return *this;
}

template <typename ContentsType>
ContentsType ListIterator<ContentsType>::operator*() {
    return myNodePointer->getValue();
}

template <typename ContentsType>
ListNode<ContentsType>* ListIterator<ContentsType>::getNodePointer() {
    return myNodePointer;
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

    return firstNodePointer->getValue();
}

template <typename ContentsType>
ContentsType List<ContentsType>::back() {
    if (lastNodePointer == NULL) {
        throw Exception("Attempted to access non-exsistent node", __FILE__, __LINE__);
    }

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
        throw Exception("Attempted to access non-exsistent node", __FILE__, __LINE__);
    }

    ListNode<ContentsType>* newFirstNodePointer = firstNodePointer->getNextNodePointer();
    delete firstNodePointer;
    rewriteFirstNodePointer(newFirstNodePointer);
    newFirstNodePointer->rewritePreviousNodePointer(NULL);
}

template <typename ContentsType>
void List<ContentsType>::pop_back() {
    if (lastNodePointer == NULL) {
        throw Exception("Attempted to access non-exsistent node", __FILE__, __LINE__);
    }

    ListNode<ContentsType>* newLastNodePointer = lastNodePointer->getPreviousNodePointer();
    delete lastNodePointer;
    rewriteLastNodePointer(newLastNodePointer);
    newLastNodePointer->rewriteNextNodePointer(NULL);
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
        baseListLastNode->rewriteNextNodePointer(addedListFirstNode);
    }
    this->rewriteLastNodePointer(addedListLastNode);

    addedListFirstNode->rewritePreviousNodePointer(baseListLastNode);
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

    ListNode<ContentsType>* iterNodePointer = iter.getNodePointer();
    ListNode<ContentsType>* afterIterNodePointer = iterNodePointer->getNextNodePointer();

    addedListFirstNode->rewritePreviousNodePointer(iterNodePointer);
    addedListLastNode->rewriteNextNodePointer(afterIterNodePointer);

    iterNodePointer->rewriteNextNodePointer(addedListFirstNode);
    if (afterIterNodePointer == NULL) {
        rewriteLastNodePointer(addedListLastNode);
    }
    else {
        afterIterNodePointer->rewritePreviousNodePointer(addedListLastNode);
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
    ListNode<ContentsType>* iteratorNodePointer = iter.getNodePointer();
    ListNode<ContentsType>* previousNodePointer = iteratorNodePointer->getPreviousNodePointer();

    ListNode<ContentsType>* newNode = new ListNode<ContentsType>(_value);
    newNode->rewriteNextNodePointer(iteratorNodePointer);
    newNode->rewritePreviousNodePointer(previousNodePointer);

    iteratorNodePointer->rewritePreviousNodePointer(newNode);

    if (previousNodePointer == NULL) {
        rewriteFirstNodePointer(newNode);
    }
    else {
        previousNodePointer->rewriteNextNodePointer(newNode);
    }

    return ListIterator<ContentsType>(newNode);
}

template <typename ContentsType>
ListIterator<ContentsType> List<ContentsType>::erase(ListIterator<ContentsType> iter) {
    ListNode<ContentsType>* iteratorNodePointer = iter.getNodePointer();
    ListNode<ContentsType>* nextNodePointer     = iteratorNodePointer->getNextNodePointer();
    ListNode<ContentsType>* previousNodePointer = iteratorNodePointer->getPreviousNodePointer();

    delete iteratorNodePointer;

    if (previousNodePointer != NULL) {
        previousNodePointer->rewriteNextNodePointer(nextNodePointer);
    }
    else {
        rewriteFirstNodePointer(nextNodePointer);
    }

    if (nextNodePointer != NULL) {
        nextNodePointer->rewritePreviousNodePointer(previousNodePointer);
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
        ListNode<ContentsType>* nextNodeToDelete = firstNodePointer->getNextNodePointer();

        while (nextNodeToDelete != NULL) {
            delete nodeToDelete;
            nodeToDelete = nextNodeToDelete;
            nextNodeToDelete = nextNodeToDelete->getNextNodePointer();
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
        nextNodePointer = nextNodePointer->getNextNodePointer();
    }

    return counter;
}
