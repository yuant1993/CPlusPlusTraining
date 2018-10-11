#include "string.h"
#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

int main() {
  char *cStr1 = (char*)"Hello, world!";
  String str1(cStr1);
  String str2(str1);
  String str3 = cStr1;
  String str4 = str3;
  cout << "str1: " << str1 << endl;
  cout << "str2: " << str1 << endl;
  cout << "str3: " << str1 << endl;
  cout << "str4: " << str1 << endl;

  char *cStr3 = (char*)"Tian";
  String str5((char*)"Yuan");
  str1.insert(6, 'y');
  str2.insert(6, str5);
  str3.insert(6, cStr3);
  cout << endl;
  cout << "After insertion:" << endl;
  cout << "str1: " << str1 << endl;
  String *strTemp = new String((char*)"Hello,y world!");
  assert(str1 == *strTemp);

  cout << "str2: " << str2 << endl;
  strTemp = new String((char*)"Hello,Yuan world!");
  assert(str2 == *strTemp);

  cout << "str3: " << str3 << endl;
  strTemp = new String((char*)"Hello,Tian world!");
  assert(str3 == *strTemp);
  delete strTemp;

  cout << endl;
  cout << "str4[3]: " << str4[3] << endl;
  assert(str4[3] == 'l');
  cout << str4[15] << endl;
  // try {
  //   cout << str4[-1] << endl;
  // } catch (out_of_range &oor) {
  //   cerr << oor.what() << endl;
  // }
}
