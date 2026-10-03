#include "Student.h"

ostream & operator<<(ostream &output, const Student &s )
{  
     output<<"Student: "<<s.LastName<<" ("<<s.FIDN<<")/"<<s.Major; 
     return output;
}
  
Student::Student(){
    FIDN="A001";
    LastName="LN";
    Major = "CS";
    GPA = 0;
}
Student::Student(string fidn){
    FIDN=fidn;
    LastName="LN";
    Major = "CS";
    GPA = 0;
}
    
Student::Student(const Student & originalS){
    FIDN=originalS.FIDN;
    LastName=originalS.LastName;
    Major = originalS.Major;
    GPA = originalS.GPA;
}

void Student::operator=(const Student & originalS){
    FIDN=originalS.FIDN;
    LastName=originalS.LastName;
    Major = originalS.Major;
    GPA = originalS.GPA;
}
    
//complete four setters and four getters for Student class

// ---------- setters ----------
void Student::setFIDN(string fidn){
    FIDN = fidn;
}

void Student::setLastName(string lastName){
    LastName = lastName;
}

void Student::setMajor(string major){
    Major = major;
}

void Student::setGPA(float gpa){
    GPA = gpa;
}

// ---------- getters ----------
string Student::getFIDN() const{
    return FIDN;
}

string Student::getLastName() const{
    return LastName;
}

string Student::getMajor() const{
    return Major;
}

float Student::getGPA() const{
    return GPA;
}
