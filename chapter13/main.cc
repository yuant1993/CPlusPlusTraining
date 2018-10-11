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
  const String str4 = str3;
  cout << "str1: " << str1 << endl;
  cout << "str2: " << str1 << endl;
  cout << "str3: " << str1 << endl;
  cout << "str4: " << str1 << endl;

  char *cStr3 = (char*)" Tian";
  String str5((char*)"Yuan");
  cout << endl;

  str1.insert(6, 'y');
  cout << "After insertion:" << endl;
  cout << "str1: " << str1 << endl;
  String *strTemp = new String((char*)"Hello,y world!");
  assert(str1 == *strTemp);

  str2.insert(6, str5);
  cout << "str2: " << str2 << endl;
  strTemp = new String((char*)"Hello,Yuan world!");
  assert(str2 == *strTemp);

  str3.insert(13, cStr3);
  cout << "str3: " << str3 << endl;
  strTemp = new String((char*)"Hello, world! Tian");
  assert(str3 == *strTemp);
  assert(*str3.begin() == 'H');
  assert(str3.size() == 18);

  cout << endl;
  str1.erase(6);
  cout << "After erasion:" << endl;
  cout << "str1: " << str1 << endl;
  strTemp = new String(cStr1);
  assert(str1 == *strTemp);

  str2.erase(6, 10);
  cout << "str2: " << str2 << endl;
  assert(str2 == *strTemp);
  delete strTemp;

  // str3.erase(10, 6);

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
