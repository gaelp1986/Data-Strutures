// Lab1.cpp -- test driver for the extended UnsortedListByArray ADT
#include <iostream>
#include <sstream>
#include <string>
#include "UnsortedListByArray.h"
using namespace std;

// print the list, 4 students per line, in the format [Student: LN (Axxx)/CS],
void PrintList(UnsortedListByArray & list)
{
    ItemType item;
    int n = list.GetLength();

    list.ResetList();
    for (int i = 1; i <= n; i++)
    {
        list.GetNextItem(item);
        cout << "[" << item << "],";
        if (i % 4 == 0)
            cout << endl;
        else
            cout << " ";
    }
    if (n % 4 != 0)
        cout << endl;
    cout << endl;
}

int main()
{
    UnsortedListByArray list;
    string line, id;

    // ---------- read the IDs from the keyboard ----------
    cout << "Please type a sequence of strings representing students' Fordham ID 'Axxx', "
         << "the range is from A000 - A250" << endl;
    cout << "one ID (A006) is repeated two times, please use white space as the delimiter:" << endl;
    getline(cin, line);
    cout << "You typed: " << line << endl << endl;

    // ---------- build the list with the OLD insert ----------
    cout << "Call the old insert item function:" << endl << endl;
    istringstream in(line);
    while (in >> id && !list.IsFull())
    {
        list.InsertItem(ItemType(Student(id)));
    }
    cout << "The list created:" << endl;
    PrintList(list);

    // ---------- delete A006 ----------
    cout << "Call the delete item function to delete Student (A006):" << endl;
    list.DeleteItem(ItemType(Student("A006")));
    cout << "The list after deleting A006 is:" << endl;
    PrintList(list);

    // ---------- Step 1: NewInsertItem ----------
    cout << "Step 1: Test new add item function:" << endl << endl;

    cout << "Call the new insert item function to insert a student (A007)" << endl;
    list.NewInsertItem(ItemType(Student("A007")));
    cout << "The list created:" << endl;
    PrintList(list);

    cout << "Call the new insert item function to insert a student (A111)" << endl;
    list.NewInsertItem(ItemType(Student("A111")));
    cout << "The list created:" << endl;
    PrintList(list);

    // ---------- Step 2: SplitList ----------
    cout << "Step 2: Test the split list function:" << endl << endl;
    cout << "The original list is" << endl;
    PrintList(list);

    string key;
    cout << " Pick one item as the key by typing it again: ";
    cin >> key;
    cout << endl << "Split with " << key << ":" << endl;

    UnsortedListByArray listOne, listTwo;
    list.SplitList(ItemType(Student(key)), listOne, listTwo);

    cout << "After split with item :" << key << ":" << endl;
    cout << "list one is :" << endl;
    PrintList(listOne);
    cout << "list two is :" << endl;
    PrintList(listTwo);
    cout << "After split, original list is :" << endl;
    PrintList(list);

    return 0;
}
