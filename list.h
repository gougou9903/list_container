template <typename ContentsType> class ListNode;
template <typename ContentsType> class ListIterator;
template <typename ContentsType> class List;

/**
 * Node class for doubly linked list
 */
template <typename ContentsType>
class ListNode {
    friend class List<ContentsType>;
public:
    ListNode* nextNodePointer;
    ListNode* previousNodePointer;
    ContentsType value;

private:
    /**
    * Constructs an empty element of the list, points to NULL by default
    */
    ListNode();

    /**
     * Constructs an element of the list, points to NULL by default
     */
    ListNode(const ContentsType& _value);
};

/**
 * List iterator class for doubly linked list, has basic arithmetic
 * operators overloaded for easy list use
 */
template <typename ContentsType>
class ListIterator {
    friend class List<ContentsType>;
public:
    ListNode<ContentsType>* myNodePointer;

    const ListIterator&   operator++(int);
    const ListIterator&   operator++();
    const ListIterator&   operator--(int);
    const ListIterator&   operator--();
    const ContentsType&   operator*();

    void rewriteNodePointer(ListNode<ContentsType>*);

private:
    /**
     * Constructs an iterator of the list
     * @param nodePointer Iterator points to the associated node
     */
    ListIterator(ListNode<ContentsType>* nodePointer);
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
    typedef ListNode<ContentsType> Node;

    Iterator begin();
    Iterator end();

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
    void splice(Iterator iter, List& addedList);

    bool empty() const;

    /**
     * Inserts the node before the node corresponding to the given iterator
     * @param Iter insert the new node before the node corrsponding to this iterator
     * @param _value New node will store this value
     * @return The iterator for the new node
     */
    Iterator insert(Iterator iter, const ContentsType& _value);

    /**
     * Deletes the node corresponding to the given iterator
     * @param iter Iterator of the element to delete
     * @return The iterator for the next node or for the end of the list if the last element was deleted
     */
    Iterator erase(Iterator iter);

    /**
     * Deletes all the elements of the list
     */
    void clear();

    long int size() const;

private:
    Node* getFirstNodePointer();
    Node* getLastNodePointer();

    void rewriteFirstNodePointer(Node* newNode);
    void rewriteLastNodePointer(Node* newNode);

    Node* firstNodePointer;
    Node* lastNodePointer;
};

#include "list_implement.h"
