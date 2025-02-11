#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "student.h"

using namespace std;

void rehash(int &listSize, student* list[]);
int hasher(int i, int size);
void generateStudents(int numStudents, vector<string>& firstNames, vector<string>& lastNames, student* list[], int& listSize);
void add(student* stu, student* list[], int& listSize);

int main() {
  srand(time(0));  // rand seed

    vector<string> firstNames;
    vector<string> lastNames;

    // load names
    ifstream firstFile("first.txt");
    ifstream lastFile("last.txt");

    string name;

    // insert into vect
    while (getline(firstFile, name)) {
      firstNames.push_back(name);
    }

    // insert into vect
    while (getline(lastFile, name)) {
      lastNames.push_back(name);
    }

    firstFile.close();
    lastFile.close();

    int listSize = 100;
    student* list[listSize];

    for (int i = 0; i < listSize; i++) {
      list[i] = NULL;
    }

    bool running = true;  // program loop
    char input[10];

    while (running) {
      cout << "Functions: ADD, DELETE, PRINT, END, GENERATE" << endl;
      cin.getline(input, 10);

      // GENERATE
      if (strcmp(input, "GENERATE") == 0) {
         int numStudents;
        cout << "Enter number of students to add: ";
        cin >> numStudents;
        cin.ignore();
        generateStudents(numStudents, firstNames, lastNames, list, listSize);
      }
      
      // ADD
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

        student* stu = new student(id, GPA, name);
        add(stu, list, listSize);
      }

      // DELETE
      else if (strcmp(input, "DELETE") == 0) {
        int id;
        cout << "Enter ID to delete: ";
        cin >> id;
        cin.ignore();

        int index = hasher(id, listSize);
        student* current = list[index];
        student* prev = NULL;

        while (current != NULL && current->getId() != id) {
          prev = current;
          current = current->getNext();
        }

        if (current == NULL) {
          cout << "Student with ID " << id << " not found." << endl;
        } else {
          if (prev == NULL) { // del head
            list[index] = current->getNext();
          } else { // del other
            prev->setNext(current->getNext());
          }
          delete current;
          cout << "Student deleted successfully." << endl;
        }
      }

      // PRINT
      else if (strcmp(input, "PRINT") == 0) {
        for (int i = 0; i < listSize; i++) {
          student* current = list[i];
          while (current != NULL) {
            cout << "ID: " << current->getId() << ", Name: " << current->getName()
                 << ", GPA: " << current->getGpa() << endl;
            current = current->getNext();
          }
        }
      }

      // END
      else if (strcmp(input, "END") == 0) {
        running = false;
      }
    }

    return 0;
}

void generateStudents(int numStudents, vector<string>& firstNames, vector<string>& lastNames, student* list[], int& listSize) {
  for (int i = 0; i < numStudents; i++) {
    // Generate random name
    int firstIndex = rand() % firstNames.size();
    int lastIndex = rand() % lastNames.size();
    string name = firstNames[firstIndex] + " " + lastNames[lastIndex];

    // Generate random ID and GPA
    int id = rand() % 1000000;  // Random 6-digit ID
    float GPA = (rand() % 401) / 100.0;  // Random GPA between 0.0 and 4.0

    student* stu = new student(id, GPA, name.c_str());
    add(stu, list, listSize);  // Add to hash table
  }
}

void add(student* stu, student* list[], int& listSize) {
  int index = hasher(stu->getId(), listSize);

  // Insert student into the list
  if (list[index] != NULL) {
    student* next1 = list[index]->getNext();
    if (next1 != NULL) {
      student* next2 = next1->getNext();
      if (next2 != NULL) {
        student* next3 = next2->getNext();
        if (next3 != NULL) {

          rehash(listSize, list);
          index = hasher(stu->getId(), listSize);
        }
        next2->setNext(stu);
      } else {
        next1->setNext(stu);
      }
    } else {
      list[index]->setNext(stu);
    }
  } else {
    list[index] = stu;
  }
}

void rehash(int &size, student* list[]) {
  int newSize = size * 2;
  student** newList = new student*[newSize];

  for (int i = 0; i < newSize; i++) {
    newList[i] = NULL;
  }

  for (int i = 0; i < size; i++) {
    student* current = list[i];
    while (current != NULL) {
      student* next = current->getNext();
      int newIndex = hasher(current->getId(), newSize);
      current->setNext(newList[newIndex]);
      newList[newIndex] = current;
      current = next;
    }
  }

  delete[] list;
  list = newList;
  size = newSize;
}

int hasher(int i, int size) {
  return i % size;
}
