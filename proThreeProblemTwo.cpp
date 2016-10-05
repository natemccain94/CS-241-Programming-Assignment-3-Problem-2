//
//  proThreeProblemTwo.cpp
// COMP241
// Fall 2015
// PA3 Problem 2
// 05 November, 2015
// Nate McCain
//

#include <iostream>
#include "UnsortedLinkedList.h"

using namespace std;



int main()
{
    // First Instance
    UnsortedType list;
    list.PutItem(6);
    list.PutItem(84);
    list.PutItem(33);
    list.PutItem(14);
    list.PutItem(4);
    
    cout << "First List" << endl << endl;
    list.PrintReversed();
    list.mergeThem();
    cout << "Should be sorted. It will print in reverse order, so it will go" << endl
         << "from greatest number to smallest number." << endl;
    list.PrintReversed();
    
    // Other Instance
    UnsortedType second;
    second.PutItem(55);
    second.PutItem(5);
    second.PutItem(15);
    second.PutItem(2);
    second.PutItem(0);
    
    cout << "Second List" << endl << endl;
    second.PrintReversed();
    second.mergeThem();
    cout << "Should be sorted. It will print in reverse order, so it will go" << endl
         << "from greatest number to smallest number." << endl;
    second.PrintReversed();
    
    return 0;
    
}