/*Exercise 6.4: Write a function that interacts with the user, asking for a
number and generating the factorial of that number. Call this function from
main.*/

#include <iostream>

using namespace std;

int factHelper(int num);
int fact() {
  int num;
  do {
    cout << "Please enter a non-negative number." << endl;
    cin >> num;
  } while (num < 0);

  factHelper(num);
}

int factHelper(int num) {
  if (num == 0) {
    return 1;
  }

  return factHelper(num - 1) * num;
}
