//  SPECIFICATION FILE Students.h 
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class  Student		// declares class data type
{						

  //output format: Student: LN (A001)/CS
  friend ostream & operator<<(ostream &output, const Student &s );

public : 			// 3 public member functions

    Student();
    Student(string fidn);
    Student(const Student & originalS); //copy constructor
    void operator=(const Student & originalS);
    
    void setFIDN(string fidn);
    void setLastName(string ln);
    void setMajor(string m);
    void setGPA(float gpa);
    
    string getLastName() const;
    string getMajor() const;
    float getGPA() const;
    string getFIDN() const;

private :			
	string  FIDN; 		//default value is A001
	string  LastName;   //default value is LN
	string  Major;      //default value is CS
	float GPA;           //default value is 0
	
} ;
#endif	