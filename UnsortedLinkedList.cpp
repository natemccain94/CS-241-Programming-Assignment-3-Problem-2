//
//  UnsortedLinkedList.cpp
// COMP241
// Fall 2015
// PA3 Problem 2
// 05 November, 2015
// Nate McCain
//

#include "UnsortedLinkedList.h"
#include <iostream>

using namespace std;

// Constructor
UnsortedType::UnsortedType()
{
    length = 0;
    listData = NULL;
}

// Is Full
bool UnsortedType::IsFull() const
{
    NodeType *location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

// Reset List
void UnsortedType::ResetList()
{
    currentPos = NULL;
}

// Get Length
int UnsortedType::GetLength() const
{
    return length;
}

// Make Empty
void UnsortedType::MakeEmpty()
{
    NodeType *temp;
    while (listData != NULL)
    {
        temp = listData;
        listData = listData->next;
        delete temp;
    }
    length = 0;
}

// Get Next Item
int UnsortedType::GetNextItem()
{
    if (currentPos == NULL)
    {
        currentPos = listData;
    }
    else
    {
        currentPos = currentPos->next;
    }
    return (currentPos->info);
}

int UnsortedType::GetItem(int item, bool &found)
{
    bool moreToSearch;
    NodeType *location;
    
    location = listData;
    found = false;
    moreToSearch = (location != NULL);
    
    while (moreToSearch && !found)
    {
        switch (ComparedTo(item))
        {
            case -1:
            case 1: location = location->next;
                moreToSearch = (location != NULL);
                break;
            case 0: found = true;
                item = location->info;
                break;
        }
    }
    return item;
}


int UnsortedType::ComparedTo(int next)
{
    if (listData->info < next)
    {
        return 1;
    }
    else if (listData->info > next)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// Put Item
void UnsortedType::PutItem(int item)
{
    NodeType *location;
    location = new NodeType;
    location->info = item;
    location->next = listData;
    listData = location;
    currentPos = listData;
    length++;
}

// Delete Item
void UnsortedType::DeleteItem(int item)
{
    NodeType *temp = new NodeType;
    if (item == listData->info)
    {
        temp = listData;
        listData = listData->next;
    }
    else
    {
        while (!(item == (listData->next)->info))
        {
            listData = listData->next;
        }
        
        temp = listData->next;
        listData->next = (listData->next)->next;
    }
    currentPos = listData;
    delete temp;
    length--;
}


// Smallest Item
int Smallest(NodeType *small, NodeType *check)
{
    if (check == NULL)
    {
        return small->info;
    }
    else
    {
        if (small->info < check->info)
        {
            return Smallest(small, check->next);
        }
        else
        {
            return Smallest(check, check->next);
        }
        
    }
}

void UnsortedType::Smaller()
{
    cout << "The smallest integer in the unsorted linked list is: " << Smallest(listData, listData->next) << endl;
}

void RevPrint(NodeType *listPtr)
{
    if (listPtr != NULL)
    {
        RevPrint(listPtr->next);
        cout << listPtr->info << endl;
    }
}

void UnsortedType::PrintReversed()
{
    RevPrint(listData);
}

// Takes two nodes, and if either are null it returns the other node.
// Otherwise, the one that is less than or equal has its next set to
// the merge of its next node and the other node. Then it will return itself.
NodeType *actualMerge(NodeType *a, NodeType *b)
{
    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }
    else if (a->info <= b->info)
    {
        a->next = actualMerge(a->next, b);
        return a;
    }
    else
    {
        b->next = actualMerge(a, b->next);
        return b;
    }
}

// Takes the list and if it or the next element is null, it returns null.
// Otherwise it sets the other node to the next list, and list next is
// set to other next, and then other next is set to the split of itself.
// Returns other.
NodeType *splitList(NodeType *list)
{
    NodeType *other;
    
    if (list == NULL)
    {
        return NULL;
    }
    else if (list->next == NULL)
    {
        return NULL;
    }
    else
    {
        other = list->next;
        list->next = other->next;
        other->next = splitList(other->next);
        return other;
    }
}

// This is the base call for the NodeType for sorting.
// It takes the list, and if it is null or the next
// item is null, it exits without doing much.
// Otherwise, it creates a node and sets it equal
// to the split of the list, and then it returns
// a merged version of the list and other.
NodeType *mergeSort(NodeType *list)
{
    NodeType *other;
    
    if (list == NULL)
    {
        return NULL;
    }
    else if (list->next == NULL)
    {
        return list;
    }
    else
    {
        other = splitList(list);
        return actualMerge(mergeSort(list),mergeSort(other));
    }
}

// This function lets the NodeType struct functions do their thing.
void UnsortedType::mergeThem()
{
    mergeSort(listData);
}












