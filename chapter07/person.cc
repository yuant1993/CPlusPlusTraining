#include "person.h"
#include <iostream>

using namespace std;

string Person::getName() const {
  return _name;
}

void Person::setName(string name) {
  _name = name;
}

string Person::getAddress() const {
  return _address;
}

void Person::setAddress(string address) {
  _address = address;
}

istream& read(istream& is, Person& per) {
  string name, address;
  getline(is, name);
  per.setName(name);
  getline(is, address);
  per.setAddress(address);
  // is >> per.name >> per.address;

  return is;
}

ostream& print(ostream& os, const Person& per) {
  os << per.getName() << ':' << per.getAddress() << endl;

  return os;
}
