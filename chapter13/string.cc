#include "string.cc"
#include <iostream>

using namespace std;

void String::alloc_n_copy(char *start, size_type length) {
  auto newStart = alloc.allocate(length);
  return {newStart, unitialized_copy(start, start + length, newStart)};
}

String::String(const char *cStr) {
  size_type len = sizeof(cStr) / sizeof(cStr[0]);
  auto newStr = alloc_n_copy(cStr, len);
  first = newStr.first;
  last = capacity = newStr.second;
}
