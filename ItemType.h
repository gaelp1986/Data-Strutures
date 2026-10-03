

//  SPECIFICATION FILE ItemType.h 
#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
#include "Student.h"
using namespace std;

const int  MAX_ITEM = 10;
enum  RelationType { LESS, EQUAL, GREATER };

class  ItemType		// declares class data type
{						

  friend ostream &operator<<(ostream &output, const ItemType& it )
  {  
     output<<it.s; 
     return output;
  }

public : 			// 3 public member functions

  ItemType(){}
  ItemType(Student s){this->s=s;}
  
  void setValue(Student s){ this->s=s;}
  
    //compare two students with their FIDN
  RelationType ComparedTo( ItemType  otherItem ) const 
  {			
    // compare the FIDN strings the same way C++ built-in string comparison does
    string myID    = s.getFIDN();
    string otherID = otherItem.s.getFIDN();

    if (myID < otherID)
        return LESS;
    else if (myID > otherID)
        return GREATER;
    else
        return EQUAL;
  }

private :			// 1 private data member
	Student s; 		 
} ;
#endif	
