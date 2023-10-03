/*
  Name : Leo Ostigaard
  Class: CSC 300
  Assignment #1
  Due: 9/25/23
  Summary: A List ADT is defined in this file. List contains Node, NodePtr and Element>
*/
using namespace std;

#include <iomanip>
#include <iostream>
#include "List.h"

/*************************************************************
*** FUNCTION <Default Constructor>
*** DESCRIPTION : <This is the default constructor. It creates an
empty List>
*** INPUT ARGS : <N/A>
*** OUTPUT ARGS : <N/A>
*** IN/OUT ARGS : <N/A>
*** RETURN : <N/A>
**************************************************************/

List::List()
{
    front = nullptr;
}

/*************************************************************
*** FUNCTION <destructor>
*** DESCRIPTION : <This is a destructor. It iterates through the
list deleting the nodes until List is empty>
*** INPUT ARGS : <N/A>
*** OUTPUT ARGS : <N/A>
*** IN/OUT ARGS : <N/A>
*** RETURN : <N/A>
**************************************************************/

List::~List()
{
    Node *nodePtr;
    Node *nextNode;

    nodePtr = front;

    while (nodePtr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }

    if(nodePtr == nullptr)
    {
        cout << endl << "The list is now empty." << endl;
    }
}

/*************************************************************
*** FUNCTION <copy constructor>
*** DESCRIPTION : <This is a copy constructor. It creates a replica of the
constructor with the same elements. It uses the add function>
*** INPUT ARGS : <const List& otherList>
*** OUTPUT ARGS : <N/A>
*** IN/OUT ARGS : <const List& otherList>
*** RETURN : <N/A>
**************************************************************/

List::List(const List& old)
{

    Node * oldNodePtr;

    front = nullptr;

    // Move through old list, appending node to this list for each node in old list
    oldNodePtr = old.front;
    while(oldNodePtr){
        add(oldNodePtr->element);
        oldNodePtr= oldNodePtr->next;
    }
}


/*************************************************************
*** FUNCTION <add>
*** DESCRIPTION : <This is the add method. It inserts a new element
to the list in descending order>
*** INPUT ARGS : <const Element>
*** OUTPUT ARGS : <N/A>
*** IN/OUT ARGS : <const Element>
*** RETURN : <N/A>
**************************************************************/

void List::add(const Element num)
{
       Node *newNode;					// A new node
       Node *nodePtr;					// To traverse the list
       Node *previousNode = nullptr;	// The previous node


       newNode = new(nothrow) Node;

       if(!newNode) {
            cout <<endl<< "Bad Memory Allocation" << endl;
            return;
       }else {
            cout <<endl<< "Good Memory Allocation" << endl;

       }

       // Allocate a new node and store num there
       newNode->element = num;

       // If there are no nodes in the list make newNode the first node
       if (!front)
       {
          front = newNode;
          newNode->next = nullptr;
        //insert newNode
       }else{
          // Position nodePtr at the front of list
          nodePtr = front;

          // Initialize previousNode to nullptr
          previousNode = nullptr;

          // Skip all nodes whose element is greater than num
          while (nodePtr && nodePtr->element > num)
          {
             previousNode = nodePtr;
             nodePtr = nodePtr->next;
          }

          // If the new node is to be the 1ast in the list,
          // insert it before all other nodes
          if (previousNode == nullptr)
          {
             front = newNode;
             newNode->next = nodePtr;
          }
          else  // Otherwise insert after the previous node
          {
             previousNode->next = newNode;
             newNode->next = nodePtr;
          }
       }
}

/*************************************************************
*** FUNCTION <remove>
*** DESCRIPTION : <This is the delete method. It iterates through the list and
deletes a node that has the element of Element (value num).
If Element isn't found, it provides feedback>
*** INPUT ARGS : <const Element num>
*** OUTPUT ARGS : <N/A>
*** IN/OUT ARGS : <const Element num>
*** RETURN : <N/A>
**************************************************************/

void List::remove(const Element num)
{
    Node *nodePtr;       // To traverse the list
    Node *previousNode;  // To point to the previous node
    bool check = false;
    // Do nothing if front points to null (list empty)
    if (!front){
        cout<< "ERROR: Can't remove element, List is empty"<<endl;
        return;
    }

    // If the first node in list is Element, delete first node
    if (front->element == num)
    {
        nodePtr = front->next;
        delete front;
        // links nodePtr to node after front
        front = nodePtr;
        check = true;
    }
    else
    {
        // Initialize nodePtr to front of list
        nodePtr = front;

        // Skip all nodes whose element is not equal to num
        while (nodePtr != nullptr && nodePtr->element != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If nodePtr is not at the end of the list, delete nodePtr
        if (nodePtr)
        {
            //skip nodePtr and link the node after previous node to the node after nodePtr
            previousNode->next = nodePtr->next;
            delete nodePtr;
            check= true;
        }
    }
    if(check == false)
    {
        cout << endl << "Element was not found.";
    }

    return;
}

/*************************************************************
*** FUNCTION <view>
*** DESCRIPTION : <This is the view method. It displays the node elements>
*** INPUT ARGS : <N/A>
*** OUTPUT ARGS : <N/A>
*** IN/OUT ARGS : <N/A>
*** RETURN : <N/A>
**************************************************************/

void List::view() const
{
    Node *nodePtr;
    nodePtr = front;

    while (nodePtr != nullptr)
    {
        cout <<  nodePtr->element << " ";
        nodePtr = nodePtr->next;
    }

    cout << endl;

    return;
}
