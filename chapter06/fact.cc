/*Exercise 6.4: Write a function that interacts with the user, asking for a
number and generating the factorial of that number. Call this function from
main.*/

#include <iostream>
#include <stdexcept>

using namespace std;

int factHelper(int num);
int fact() {
  int num;
  cout << "Please enter a non-negative integer number" << endl;
  cin >> num;

  try {
    return factHelper(num);
  } catch(const invalid_argument &e) {
    cerr << e.what() << endl;
    return 0;
  }
}

int factHelper(int num) {
  if (num < 0) {
    throw invalid_argument("No factorial for negative number");
  }

  if (num == 0) {
    return 1;
  }

  return factHelper(num - 1) * num;
}
