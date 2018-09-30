/*Exercise 7.4: Write a class named Person that represents the name and address of a person.
Use a string to hold each of these elements. Subsequent exercises will incrementally add features to this class.
Exercise 7.5: Provide operations in your Person class to return the name and address.
Should these functions be const? Explain your choice.
Exercise 7.9: Add operations to read and print Person objects to the code you wrote for the exercises in ? 7.1.2 (p. 260).
Exercise 7.15: Add appropriate constructors to your Person class.
Exercise 7.22: Update your Person class to hide its implementation.*/

#include <iostream>

using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person {
friend istream& read(istream&, Person&);
friend ostream& print(ostream&, const Person&);

public:
  Person() = default;
  Person(const string& n) : name(n) {}
  Person(const string& n, const string& a) : name(n), address(a) {}
  string getName() const;
  string getAddress() const;

private:
  string name;
  string address;
};

istream& read(istream&, const Person&);
ostream& print(ostream&, const Person&);

#endif
