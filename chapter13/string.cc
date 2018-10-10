#include "string.h"
#include <iostream>
#include <stdexcept>

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
  size_t len = sizeof(cStr) / sizeof(cStr[0]);
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
  size_t len = sizeof(cStr) / sizeof(cStr[0]);
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
    throw out_of_range("Wrong position to insert");
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
    throw out_of_range("Wrong position to insert");
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
  size_t insertSize = sizeof(cStr) / sizeof(cStr[0]);
  if (p < 0 || p > size()) {
    throw out_of_range("Wrong position to insert");
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
