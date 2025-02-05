#include <iostream>
#include <cstring>

class student{

public:
  student(int i, float gp, const char* n);
  int getId(); 
  double getGpa();
  char* getName();
  student* getNext();
  void setNext(student* s);
  student* next;
 
  int id;
  char name[40];
  float gpa;
  
};
