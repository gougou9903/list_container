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

    ContentsType* getValuePointer() const;
    ListNode<ContentsType>* getNextNodePointer() const;
    ListNode<ContentsType>* getPreviousNodePointer() const;
    void rewriteNextNodePointer(const ListNode<ContentsType>* nodePointer);
    void rewritePreviousNodePointer(const ListNode<ContentsType>* nodePointer);

private:
    ListNode<ContentsType>* nextNodePointer;
    ListNode<ContentsType>* previousNodePointer;
    ContentsType value;
};

/**
 * Doubly linked list class
 */
template <typename ContentsType> class List {
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

    void rewriteFirstNodePointer(const ListNode<ContentsType>*);
    void rewriteLastNodePointer(const ListNode<ContentsType>*);

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
