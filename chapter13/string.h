/*Exercise 13.44: Write a class named String that is a simplified version of
the library string class. Your class should have at least a default
constructor and a constructor that takes a pointer to a C-style string. Use an
allocator to allocate memory that your String class uses.*/
#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <memory>
#include <utility>

class String {
public:
  String() = default;
  String(const char *cStr);
  String(const String &str);
  String &operator=(const char *cStr);
  String &operator=(const String &str);
  ~String();
  size_t size() const {return last - first;}
  size_t capacity() const {return cap - first;}
  char *begin() const {return first;}
  char *end() const {return last;}
  char front() const {return *first;}
  char back() const {return *(last - 1);}
  String &insert(size_t p, const char &c);
  String &insert(size_t p, const String &str);
  String &insert(size_t p, const char *cStr);
private:
  std::allocator<char> alloc;
  void check_cap() {if (size() == capacity()) reallocate();}
  std::pair<char*, char*> alloc_n_copy(const char *start, size_t length);
  char *first;
  char *last;
  char *cap;
  void free();
  void reallocate();
};

#endif
