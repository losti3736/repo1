// Implementation Files (.cpp)
#include "List.h"
// preprocessor directives
#include <iostream>

using namespace std;

int main() {
    List myList;
    cout << "List contents: ";
    myList.view();

    cout << "Performing invalid removal: "<<endl;
    myList.remove(1);
    myList.add(40.05);
    myList.add(30.05);
    myList.add(20.5);
    myList.add(5);
    myList.add(50);

    cout << "List contents after adding elements: ";
    myList.view();
    cout << endl;

    cout << "Removing 20.5: ";
    myList.remove(20.5);
    cout << endl;

    cout << "List contents: ";
    myList.view();
    myList.remove(35);

    cout << "Removing 50: ";
    myList.remove(50);
    cout << endl;

    cout << "List contents: ";
    myList.view();

    cout << "Performing invalid removal: "<<endl;
    cout << "Removing 50: ";
    myList.remove(50);
    cout << endl;

    cout << "List contents: ";
    myList.view();



    return 0;
}


