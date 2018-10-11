#include "string.h"
#include <iostream>
#include <stdexcept>
#include <string.h>

using namespace std;

pair<char*, char*> String::alloc_n_copy(const char *start, size_t length) {
  auto newStart = alloc.allocate(length);
  return {newStart, uninitialized_copy(start, start + length, newStart)};
}

void String::free() {
  if (first) {
    for (auto itr = last; itr != first;) {
      alloc.destroy(--itr);
    }
    alloc.deallocate(first, cap - first);
  }
}

String::String(const char *cStr) {
  size_t len = strlen(cStr);
  auto newStr = alloc_n_copy(cStr, len);
  first = newStr.first;
  last = cap = newStr.second;
}

String::String(const String &str) {
  size_t len = str.size();
  auto newStr = alloc_n_copy(str.begin(), len);
  first = newStr.first;
  last = cap = newStr.second;
}

String &String::operator=(const char *cStr) {
  size_t len = strlen(cStr);
  auto newStr = alloc_n_copy(cStr, len);
  free();
  first = newStr.first;
  last = cap = newStr.second;
  return *this;
}

String &String::operator=(const String &str) {
  size_t len = str.size();
  auto newStr = alloc_n_copy(str.begin(), len);
  free();
  first = newStr.first;
  last = cap = newStr.second;
  return *this;
}

String::~String() {
  free();
}

void String::reallocate() {
  size_t newLen = size() ? 2 * size() : 1;
  auto newStart = alloc.allocate(newLen);
  auto newEnd = uninitialized_copy(begin(), end(), newStart);
  free();
  first = newStart;
  last = newEnd;
  cap = first + newLen;
}

String &String::insert(size_t p, const char &c) {
  if (p < 0 || p > size()) {
    throw out_of_range("Position to insert out of range");
  }
  if (cap == last) {
    reallocate();
  }
  for (auto itr = last; itr > first + p; --itr) {
    *itr = *(itr - 1);
  }
  alloc.construct(first + p, c);
  //*(first + p) = c;
  last++;
  return *this;
}

String &String::insert(size_t p, const String &str) {
  size_t insertSize = str.size();
  if (p < 0 || p > size()) {
    throw out_of_range("Position to insert out of range");
  }
  while (size() + insertSize > capacity()) {
    reallocate();
  }
  for (auto itr = last - 1 + insertSize; itr >= first + p + insertSize; --itr) {
    *itr = *(itr - insertSize);
  }
  copy(str.begin(), str.end(), first + p);
  last = last + insertSize;
  return *this;
}

String &String::insert(size_t p, const char *cStr) {
  size_t insertSize = strlen(cStr);
  if (p < 0 || p > size()) {
    throw out_of_range("Position to insert out of range");
  }
  while (size() + insertSize > capacity()) {
    reallocate();
  }
  for (auto itr = last - 1 + insertSize; itr >= first + p + insertSize; --itr) {
    *itr = *(itr - insertSize);
  }
  copy(cStr, cStr + insertSize, first + p);
  last = last + insertSize;
  return *this;
}

char &String::operator[](size_t n) {
  if (n < 0 || n >= size()) {
    cerr << "Index out of range" << endl;
    // throw out_of_range("Index out of range");
  }
  return *(first + n);
}

const char &String::operator[](size_t n) const {
  if (n < 0 || n >= size()) {
    cerr << "Index out of range" << endl;
    // throw out_of_range("Index out of range");
  }
  return *(first + n);
}

ostream &operator<<(ostream &os, const String &str) {
  auto itr = str.begin();
  while(itr != str.end()) {
    os << *itr++;
  }
  return os;
}

bool operator==(const String &str1, const String &str2) {
  if (str1.size() != str2.size()) {
    return false;
  }
  for (auto itr1 = str1.begin(), itr2 = str2.begin(); itr1 != str1.end(); ++itr1, ++itr2) {
    if (*itr1 != *itr2) {
      return false;
    }
  }
  return true;
}
