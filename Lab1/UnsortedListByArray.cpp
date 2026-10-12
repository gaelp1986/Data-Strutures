// IMPLEMENTATION FILE UnsortedListByArray.cpp
#include "UnsortedListByArray.h"

UnsortedListByArray::UnsortedListByArray()
{
    length = 0;
    currentPos = -1;
}

void UnsortedListByArray::MakeEmpty()
{
    length = 0;
}

bool UnsortedListByArray::IsFull() const
{
    return (length == MAX_ITEM);
}

bool UnsortedListByArray::IsEmpty() const
{
    return (length == 0);
}

int UnsortedListByArray::GetLength() const
{
    return length;
}

void UnsortedListByArray::RetrieveItem(ItemType& item, bool& found)
{
    bool moreToSearch;
    int location = 0;
    found = false;
    moreToSearch = (location < length);

    while (moreToSearch && !found)
    {
        switch (item.ComparedTo(info[location]))
        {
            case LESS    :
            case GREATER : location++;
                           moreToSearch = (location < length);
                           break;
            case EQUAL   : found = true;
                           item = info[location];
                           break;
        }
    }
}

void UnsortedListByArray::InsertItem(ItemType item)
{
    info[length] = item;
    length++;
}

void UnsortedListByArray::DeleteItem(ItemType item)
{
    int location = 0;

    while (item.ComparedTo(info[location]) != EQUAL)
        location++;

    info[location] = info[length - 1];
    length--;
}

void UnsortedListByArray::ResetList()
{
    currentPos = -1;
}

void UnsortedListByArray::GetNextItem(ItemType& item)
{
    currentPos++;
    item = info[currentPos];
}

// ------------------------------------------------------------
// NewInsertItem: inserts newItem only if it is not already in
// the list. Returns true if inserted, false if a duplicate exists.
// Does NOT call any other member functions (per lab rules).
// ------------------------------------------------------------
bool UnsortedListByArray::NewInsertItem(ItemType newItem)
{
    // 1. scan the whole list looking for a duplicate
    for (int i = 0; i < length; i++)
    {
        if (newItem.ComparedTo(info[i]) == EQUAL)
            return false;              // already there, don't insert
    }

    // 2. no room left (can't call IsFull(), so check length directly)
    if (length == MAX_ITEM)
        return false;

    // 3. not found -> put it at the end
    info[length] = newItem;
    length++;
    return true;
}

// ------------------------------------------------------------
// SplitList: listOne gets items with key <= item's key,
// listTwo gets items with key > item's key.
// Original list is left unchanged; relative order is preserved.
// ------------------------------------------------------------
void UnsortedListByArray::SplitList(ItemType item,
                                    UnsortedListByArray & listOne,
                                    UnsortedListByArray & listTwo)
{
    for (int i = 0; i < length; i++)
    {
        if (info[i].ComparedTo(item) == GREATER)
            listTwo.InsertItem(info[i]);
        else                          // LESS or EQUAL
            listOne.InsertItem(info[i]);
    }
}
