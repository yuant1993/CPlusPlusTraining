/*Exercise 7.4: Write a class named Person that represents the name and address of a person.
Use a std::string to hold each of these elements. Subsequent exercises will incrementally add features to this class.
Exercise 7.5: Provide operations in your Person class to return the name and address.
Should these functions be const? Explain your choice.
Exercise 7.9: Add operations to read and print Person objects to the code you wrote for the exercises in ? 7.1.2 (p. 260).
Exercise 7.15: Add appropriate constructors to your Person class.
Exercise 7.22: Update your Person class to hide its implementation.*/
#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person {
// friend istream& read(istream&, Person&);
// friend ostream& print(ostream&, const Person&);

public:
  Person() = delete;
  Person(const std::string &n) : _name(n) {}
  Person(const std::string &n, const std::string &a) : _name(n), _address(a) {}
  Person(std::istream &is);
  std::string getName() const;
  void setName(std::string name);
  std::string getAddress() const;
  void setAddress(std::string address);

private:
  std::string _name;
  std::string _address;
};

std::istream& read(std::istream&, Person&);
std::ostream& print(std::ostream&, const Person&);

#endif
