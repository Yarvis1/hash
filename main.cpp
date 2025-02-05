#include <iostream>
#include <string>
#include <cstring>
#include "student.h"
#include <fstream>
using namespace std;

int hasher(int i,int size);
int main(){
  int listSize = 100;
  student* list[listSize];
  for(int i=0;i<listSize+1;i++){
    list[i]=NULL;
  }
  bool running = true;//run loop
  char input[10];
  while (running!=false) {
    cout << "Functions: ADD, DELETE, PRINT, END" << endl;
    cin.getline(input, 10);
    //add  
  if (strcmp(input, "ADD") == 0) {
    int id;
    char name[40];
    float GPA;
    cout << "Enter ID number: ";
    cin >> id;
    cin.ignore();
    cout << "Enter name: ";
    cin.getline(name, 40);
    cout << "Enter GPA: ";
    cin >> GPA;
    student* stu=new student(id,GPA,name);
    int index = hasher(id,listSize);
    if (list[index]=NULL){
    list[index] = stu;
    }
    else{
    list[index]->setNext(stu);
    }
  }  
  //delete
  else if (strcmp(input, "DELETE") == 0) {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    cin.ignore();
  }
  //print from head
  else if (strcmp(input, "PRINT") == 0) { 
    for(int i=0;i<listSize+1;i++){
      if(list[i]=NULL){
	
      }
      else{
	if(list[i]->getNext()==NULL){
	  cout<<"id: "<<list[i]->getId()<<endl;
	  cout<<"name: "<<list[i]->getName()<<endl;
	  cout<<"GPA: "<<list[i]->getGpa()<<endl;
	}
	else{
	  student* nextstu= list[i]->getNext();
	  cout<<"id: "<<list[i]->getId()<<endl;
          cout<<"name: "<<list[i]->getName()<<endl;
          cout<<"GPA: "<<list[i]->getGpa()<<endl;
	  cout<<"id: "<<nextstu->getId()<<endl;
          cout<<"name: "<<nextstu->getName()<<endl;
          cout<<"GPA: "<<nextstu->getGpa()<<endl;
	}
      }
    }
  }
  
  //quit while loop
  else if (strcmp(input, "END") == 0) {
    running = false;
  }
  else {
    cout << "Not valid input" << endl;
    cin.ignore();
  }
  }
  return 0;
}



int hasher(int i, int size){
  return (i % size);
}

//char generateName(){

//}
