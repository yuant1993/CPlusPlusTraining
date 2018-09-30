/*Exercise 11.31: Write a program that defines a multimap of authors and
their works. Use find to find an element in the multimap and erase that
element. Be sure your program works correctly if the element you look for is
not in the map.*/

#include <iostream>
#include <map>

using namespace std;

void eraseElement(multimap<string, string>& map, const pair<string, string>& element) {
  for (auto itr = map.equal_range(element.first); itr.first != itr.second; ++itr.first) {
    if (itr.first->second == element.second) {
      map.erase(itr.first);
      break;
    }
  }
}

void printMap(multimap<string, string>& map) {
  cout << "map count: " << map.size() << endl;

  auto itr = map.cbegin();
  while (itr != map.cend()) {
    cout << itr->first << ", " << itr->second << endl;
    ++itr;
  }
}

int main() {
  multimap<string, string> authors{{"Yuan 1 Tian", "Yuan's work 1.1"}, {"Yuan 1 Tian", "Yuan's work 1.2"}, {"Yuan 2 Tian", "Yuan's work 2"}, {"Yuan 3 Tian", "Yuan's work 3.1"}, {"Yuan 3 Tian", "Yuan's work 3.2"}, {"Yuan 3 Tian", "Yuan's work 3.3"}, {"Yuan 4 Tian", "Yuan's work 4"}};

  cout << "Original authors map:" << endl;
  printMap(authors);
  cout << endl;

  eraseElement(authors, {"Yuan 3 Tian", "Yuan's work 3.2"});
  cout << "After erasing an existing element {\"Yuan 3 Tian\", \"Yuan's work 3.2\"}:" << endl;
  printMap(authors);
  cout << endl;

  eraseElement(authors, {"Yuan 5 Tian", "Yuan's work 2"});
  cout << "After erasing a non-existing author {\"Yuan 5 Tian\", \"Yuan's work 2\"}:" << endl;
  printMap(authors);
  cout << endl;

  eraseElement(authors, {"Yuan 3 Tian", "Yuan's work 3.4"});
  cout << "After erasing a non-existing work of an author {\"Yuan 3 Tian\", \"Yuan's work 3.4\"}:" << endl;
  printMap(authors);
  cout << endl;
}
