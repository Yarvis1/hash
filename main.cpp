#include <iostream>
#include <string>
#include <cstring>
#include "student.h"
using namespace std;

int hash(int i);
int main(){
  int listSize = 100;
  student* list[listSize];
  bool running = true;//run loop
  char input[10];

  while (running!=false) {
    cout << "Functions: ADD, DELETE, PRINT, END,AVE" << endl;
    cin.getline(input, 10);
    //add
  }
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
    cin.ignore();
    
 
    
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
    
  }
  //quit while loop
  else if (strcmp(input, "END") == 0) {
    running = false;
    
  }
  else {
    cout << "Not valid input" << endl;
  }
  return 0;
}
int hash(int i, int size){
  return (i % size);
    }

