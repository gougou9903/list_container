template <typename ContentsType> class ListNode {
public:
    ListNode(ContentsType* value, ListNode* nextCellPointer, ListNode* previousCellPointer);

    ContentsType*   getValue();
    ListNode*       getNextCellPointer();
    ListNode*       getPreviousCellPointer();
    void            rewriteNextCellPointer();
    void            rewritePreviousCellPointer();

private:
    ListNode*       nextCellPointer;
    ListNode*       previousCellPointer;
    ContentsType    value;
};

template <typename ContentsType> class List {
public:
    List(ContentsType);
    List(uint32_t elementsNumber, ContentsType value);

    push_back(ContentsType value);
    push_front(ContentsType value);
private:

};
