list_container
==============

This is a learning project, it doesn't match real std::list in neither functionality nor speed. Template class, supports any object type.

Following STL-like constructors supported:
- List() - creates an empty list with no nodes
- List(_val) - creates a list with one node, which stores _val value inside of it
- List(_num, _val) - creates a list with _num nodes, each of them stores _val value inside of it

Following STL-like methods are supported:
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
- empty
- insert
- erase
- clear
- size

Container is based on the following structure:

List (doubly linked list) consists of nodes. List object itself stores only pointers to the first and the last nodes.

Node objects have pointers to next, previous nodes and stores user value.

On the user side interaction with the list elements is done with the help of bilinear Iterator objects. Following operators are overloded for them:
- to get the corresponding node value: "*"
- to travel between the nodes: "+", "-", "++", "--" (both postfix and prefix form for the last two) (incrementing iterator returns iterator to the next node and so on).


Use doxygen to get more detailed documentation.
