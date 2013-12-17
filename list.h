/**
 * Node class for doubly linked list
 */
template <typename ContentsType>
class ListNode {
public:
    /**
    * Constructs an empty element of the list, points to NULL by default
    */
    ListNode();

    /**
     * Constructs an element of the list, points to NULL by default
     */
    ListNode(const ContentsType& _value);

    ContentsType getValue() const;

    ListNode* getNextNodePointer();
    ListNode* getPreviousNodePointer();
    void rewriteNextNodePointer(ListNode* nodePointer);
    void rewritePreviousNodePointer(ListNode* nodePointer);

private:
    ListNode* nextNodePointer;
    ListNode* previousNodePointer;
    ContentsType value;
};

/**
 * List iterator class for doubly linked list, has basic arithmetic
 * operators overloaded for easy list use
 */
template <typename ContentsType>
class ListIterator {
public:
    /**
     * Constructs an iterator of the list
     * @param nodePointer Iterator points to the associated node
     */
    ListIterator(ListNode<ContentsType>* nodePointer);

    ListIterator operator+(int steps);
    ListIterator operator++(int);
    ListIterator operator++();
    ListIterator operator-(int steps);
    ListIterator operator--(int);
    ListIterator operator--();
    ContentsType operator*();


    ListNode<ContentsType>* getNodePointer();
    void rewriteNodePointer(ListNode<ContentsType>*);

private:
    ListNode<ContentsType>* myNodePointer;
};

/**
 * Doubly linked list class
 */
template <typename ContentsType>
class List {
public:
    /**
     * Constructs an empty list
     */
    List();

    /**
    * Constructs a list
    * @param _value Value saved in the first list node
    */
    List(const ContentsType& _value);

    /**
     * Constructs a list
     * @param elementsNumber Number of list nodes
     * @param _value Value saved in all created list nodes
     */
    List(int elementsNumber, const ContentsType& _value);

    ~List();

    typedef ListIterator<ContentsType> Iterator;

    ListIterator<ContentsType> begin();
    ListIterator<ContentsType> end();

    ContentsType front();
    ContentsType back();


    /**
     * Adds a node to the front of the list
     * @param _value Value saved in the new list node
     */
    void push_front(const ContentsType& _value);

    /**
     * Adds a node to the back of the list
     * @param _value Value saved in the new list node
     */
    void push_back(const ContentsType& _value);

    void pop_front();
    void pop_back();

    /**
     * Concatenates calling list and the list given as an arguement
     * @param addedList Elements of this list will be placed to the end of
     * the calling list, will be left empty afterwards (not deleted)
     */
    void concat(List& addedList);

    /**
     * Adds elements of the list given as an arguement to the calling list at the iterator position
     * @param Iter adds elements after this iterator position
     * @param AddedList elements of this list will added tothe calling list,
     * will be left empty afterwards (not deleted)
     */
    void splice(ListIterator<ContentsType> iter, List& addedList);

    bool empty() const;

    /**
     * Inserts the node before the node corresponding to the given iterator
     * @param Iter insert the new node before the node corrsponding to this iterator
     * @param _value New node will store this value
     * @return The iterator for the new node
     */
    ListIterator<ContentsType> insert(ListIterator<ContentsType> iter,
                                      const ContentsType& _value);

    /**
     * Deletes the node corresponding to the given iterator
     * @param iter Iterator of the element to delete
     * @return The iterator for the next node or for the end of the list if the last element was deleted
     */
    ListIterator<ContentsType> erase(ListIterator<ContentsType> iter);

    /**
     * Deletes all the elements of the list
     */
    void clear();

    long int size() const;

private:
    ListNode<ContentsType>* getFirstNodePointer();
    ListNode<ContentsType>* getLastNodePointer();

    void rewriteFirstNodePointer(ListNode<ContentsType>* newNode);
    void rewriteLastNodePointer(ListNode<ContentsType>* newNode);

    ListNode<ContentsType>* firstNodePointer;
    ListNode<ContentsType>* lastNodePointer;
};

#include "list_implement.h"
