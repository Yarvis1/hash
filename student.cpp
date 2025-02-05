#include<iostream>
#include<cstring>
#include "student.h"
student::student(int i, float gp,const char* n){
  id=i;
  gpa=gp;
  strncpy(name,n,40);
}
int student::getId(){
  return id;
}
char*  student::getName(){
  return name;
}
double student::getGpa(){
  return id;
}
student* student::getNext(){
  return next;
}
void student::setNext(student* s){
  next=s;
}
