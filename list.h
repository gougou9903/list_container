/**
 * Node class for doubly linked list
 */
template <typename ContentsType>
class ListNode {
public:
    /**
    * Constructor for empty element of the list, points to itself
    */
    ListNode();

    /**
     * Constructor for element of the list, points to itself
     */
    ListNode(const ContentsType& _value);
    // ListNode(const ContentsType& _value, ListNode* _nextNodePointer, ListNode* _previousNodePointer);

    ContentsType* getValue() const;
    ListNode<ContentsType>* getNextNodePointer() const;
    ListNode<ContentsType>* getPreviousNodePointer() const;
    void rewriteNextNodePointer(const ListNode<ContentsType>*);
    void rewritePreviousNodePointer(const ListNode<ContentsType>*);

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
     * Basic constructor, creates an empty list object
    */
    List();

    /**
    * Basic constructor, creates a list object
    * @param _value Value saved in the first list node
    */
    List(ContentsType _value);

    /**
     * Basic constructor, creates a list object
     * @param elementsNumber Number of list nodes
     * @param _value Value saved in all created list nodes
     */
    List(int elementsNumber, ContentsType _value);

    void rewriteFirstNodePointer(const ListNode<ContentsType>*);
    void rewriteLastNodePointer(const ListNode<ContentsType>*);

    /**
     * Add a node to the front of the list
     * @param _value Value saved in the new list node
     */
    void push_front(ContentsType _value);
    void push_back(ContentsType _value);

private:
    ListNode<ContentsType>* firstNodePointer;
    ListNode<ContentsType>* lastNodePointer;
};




