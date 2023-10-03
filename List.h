/*
  Name : Leo Ostigaard
  Class: CSC 300
  Assignment #1
  Due: 9/25/23
  Summary: A List ADT is declared in this file. List contains Node, NodePtr and Element
*/

#ifndef LIST_H_
#define LIST_H_

typedef float Element;

class List {
public:

/*************************************************************
*** FUNCTION <Default Constructor>
*** DESCRIPTION : <This is the default constructor. It creates an empty List>
*** INPUT ARGS : <N/A>
*** OUTPUT ARGS : <N/A>
*** IN/OUT ARGS : <N/A>
*** RETURN : <N/A>
**************************************************************/

    List();

/*************************************************************
*** FUNCTION <copy constructor>
*** DESCRIPTION : <This is a copy constructor. It creates a replica of the constructor with the same elements. It uses the add function
*** INPUT ARGS : <const List& otherList>
*** OUTPUT ARGS : <N/A>
*** IN/OUT ARGS : <const List& otherList>
*** RETURN : <N/A>
**************************************************************/

    List(const List&);

/*************************************************************
*** FUNCTION <destructor>
*** DESCRIPTION : <This is a destructor. It iterates through the list deleting the nodes until List is empty>
*** INPUT ARGS : <N/A>
*** OUTPUT ARGS : <N/A>
*** IN/OUT ARGS : <N/A>
*** RETURN : <N/A>
**************************************************************/

    ~List();

/*************************************************************
*** FUNCTION <add>
*** DESCRIPTION : <This is the add method. It inserts a new element to the list in descending order>
*** INPUT ARGS : <const Element>
*** OUTPUT ARGS : <N/A>
*** IN/OUT ARGS : <const Element>
*** RETURN : <N/A>
**************************************************************/

    void add(const Element);
/*************************************************************
*** FUNCTION <remove>
*** DESCRIPTION : <This is the add method. It inserts a new element to the list in descending order>
*** INPUT ARGS : <const Element>
*** OUTPUT ARGS : <N/A>
*** IN/OUT ARGS : <const Element>
*** RETURN : <N/A>
**************************************************************/

    void remove(const Element);

/*************************************************************
*** FUNCTION <view>
*** DESCRIPTION : <This is the delete method. It iterates through the list and deletes a node that has the element of Element>
*** INPUT ARGS : <const Element>
*** OUTPUT ARGS : <N/A>
*** IN/OUT ARGS : <const Element>
*** RETURN : <N/A>
**************************************************************/

    void view() const;

private:

    struct Node;
    typedef Node* NodePtr;
    struct Node {
        Element element;
        NodePtr next;
    };
    NodePtr front;

};

#endif
