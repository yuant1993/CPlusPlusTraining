#include "person.h"
#include <iostream>

using namespace std;

string Person::getName() const {
  return name;
}

string Person::getAddress() const {
  return address;
}

istream& read(istream& is, Person& per) {
  is >> per.name >> per.address;

  return is;
}

ostream& print(ostream& os, const Person& per) {
  os << per.getName() << ':' << per.getAddress() << endl;

  return os;
}
