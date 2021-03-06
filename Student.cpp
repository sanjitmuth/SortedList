#include <iostream>
#include <fstream>
#include <string>

#include "Student.h"

using namespace std;

//Constructors---------------
Student::Student() {
  id = -1;
  name = "None";
} //default

Student::Student(int i, string s) {
  id = i;
  name = s;
} //2 param

//Getters-------------------
int Student::getID() const {
  return id;
}

string Student::getName() const {
  return name;
}

//Setters-------------------
void Student::setID(int i) {
  id = i;
}

void Student::setName(string s) {
  name = s;
}

//Operator Overloads----------
bool Student::operator==(const Student& s) const {
  if (this->id == s.getID()) {
    return true;
  } else {
    return false;
  }
}

bool Student::operator<(const Student& s) const {
  if (this->id < s.getID()) {
    return true;
  } else {
    return false;
  }
}

bool Student::operator>(const Student& s) const {
  if (this->id > s.getID()) {
    return true;
  } else {
    return false;
  }
}

bool Student::operator!=(const Student& s) const {
  if (this->id != s.getID()) {
    return true;
  } else {
    return false;
  }
}
