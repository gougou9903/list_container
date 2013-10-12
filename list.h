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

    /**
     * @return Pointer to the element's value
     */
    ContentsType* getValuePointer() const;

    /**
     * @return Pointer to the next node
     */
    ListNode<ContentsType>* getNextNodePointer() const;

    /**
     * @return Pointer to the previous node
     */
    ListNode<ContentsType>* getPreviousNodePointer() const;

    /**
     * @param Pointer to the new next node
     */
    void rewriteNextNodePointer(const ListNode<ContentsType>*);

    /**
     * @param Pointer to the new previous node
     */
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
    List(const ContentsType& _value);

    /**
     * Basic constructor, creates a list object
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
    void push_back(const ContentsType& _value);

private:
    ListNode<ContentsType>* firstNodePointer;
    ListNode<ContentsType>* lastNodePointer;
};
