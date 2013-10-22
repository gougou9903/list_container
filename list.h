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
    ListIterator<ContentsType> operator++(int);
    ListIterator<ContentsType> operator++();
    ListIterator<ContentsType> operator-(int steps);
    ListIterator<ContentsType> operator--(int);
    ListIterator<ContentsType> operator--();

    ListNode<ContentsType>* getNodePointer();
    void rewriteNodePointer(ListNode<ContentsType>*);

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

    ~List();

    ListIterator<ContentsType> begin();
    ListIterator<ContentsType> end();

    ContentsType front();
    ContentsType back();

    ListNode<ContentsType>* getFirstNodePointer();
    ListNode<ContentsType>* getLastNodePointer();

    void rewriteFirstNodePointer(ListNode<ContentsType>* newNode);
    void rewriteLastNodePointer(ListNode<ContentsType>* newNode);

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
     * @param addedList elements of this list will be placed to the end of
     * the calling list, will be left empty afterwards (not deleted)
     */
    void concat(List<ContentsType>& addedList);

    /**
     * Adds elements of the list given as an arguement to the calling list at the iterator position
     * @param iter adds elements after this iterator position
     * @param addedList elements of this list will added tothe calling list,
     * will be left empty afterwards (not deleted)
     */
    void splice(ListIterator<ContentsType> iter, List<ContentsType>& addedList);

    /**
     * Deletes the node of the given iterator
     * @param iter iterator of the element to delete
     * @return the iterator for the next node or for the end of the list if the last element was deleted
     */
    ListIterator<ContentsType> erase(ListIterator<ContentsType> iter);

    /**
     * Deletes all the elements of the list
     */
    void clear();

    long int size() const;

private:
    ListNode<ContentsType>* firstNodePointer;
    ListNode<ContentsType>* lastNodePointer;
};
