#include "person.h"
#include <iostream>

using namespace std;

int main() {
  Person per1("Jimmy");
  Person per2("Yuan Tian", "2345 Bishop St, Ann Arbor, MI, 48105");
  cout << per1.getName() << ':' << per1.getAddress() << endl;
  cout << per2.getName() << ':' << per2.getAddress() << endl;
  cout << "Please enter a person's name and address:" << endl;
  read(cin, per1);
  print(cout, per1);
  cout << per1.getName() << ':' << per1.getAddress() << endl;
}
