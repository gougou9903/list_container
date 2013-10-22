list_container
==============

Template class, supports any object type.

Following STL methods are supported:
- push_front
- push_back
- pop_front
- pop_back
- begin
- end
- front
- back
- concat (merge without sorting)
- splice
- clear
- size

Container is based on the following structure:

List (doubly linked list) consists of nodes. List object itself stores only pointers to the first and the last nodes.

Node objects have pointers to next, previous nodes and stores user value.

On the user side interaction with the list elements is done with the help of Iterator objects. Following operators are overloded for them: +, ++ (postfix and prefix form), -, -- (postfix and prefix form) (incrementing iterator returns iterator to the next node and so on).
