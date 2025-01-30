#include <iostream>
#include <cstring>

class student{

public:
  student(int i, float gp, const char* n);
  int getId();
  void setNext();
  student* getNext();
 private:
  int id;
  const char* name[20];
  float gpa;
  student* next;
};
