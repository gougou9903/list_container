/**
 * Node class for doubly linked list
 */
template <typename ContentsType>
class ListNode {
public:
    /**
    * Constructs and empty element of the list, points to NULL by default
    */
    ListNode();

    /**
     * Constructs and element of the list, points to NULL by default
     */
    ListNode(const ContentsType& _value);

    ContentsType getValue() const;

    ListNode<ContentsType>* getNextNodePointer();
    ListNode<ContentsType>* getPreviousNodePointer();
    void rewriteNextNodePointer(ListNode<ContentsType>* nodePointer);
    void rewritePreviousNodePointer(ListNode<ContentsType>* nodePointer);

    // ListNode<ContentsType>* operator+(int steps);

private:
    ListNode<ContentsType>* nextNodePointer;
    ListNode<ContentsType>* previousNodePointer;
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
     * @param nodePointer Iterator points to the node associated pointer
     */
    ListIterator(ListNode<ContentsType>* nodePointer);

    ListIterator<ContentsType> operator+(int steps);
    ContentsType getNodeValue() const;

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

    ListIterator<ContentsType> begin();
    ListIterator<ContentsType> end();

    ContentsType front();
    ContentsType back();

    ListNode<ContentsType>* getFirstNodePointer();
    ListNode<ContentsType>* getLastNodePointer();

    void rewriteFirstNodePointer(ListNode<ContentsType>* newNode);
    void rewriteLastNodePointer(ListNode<ContentsType>* newNode);

    /**
     * Add a node to the front of the list
     * @param _value Value saved in the new list node
     */
    void push_front(const ContentsType& _value);

    /**
     * Add a node to the back of the list
     * @param _value Value saved in the new list node
     */
    void push_back(const ContentsType& _value);

private:
    ListNode<ContentsType>* firstNodePointer;
    ListNode<ContentsType>* lastNodePointer;
};
