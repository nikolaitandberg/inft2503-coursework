#include "set.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

Set::Set() {};

Set::Set(const Set &other) {
  table = other.table;
}

Set::Set(std::vector<int> _table) {
  table = _table;
}

Set &Set::operator+=(int x) {
  for (auto i : table) {
    if (i == x)
      return *this;
  }
  table.push_back(x);
  return *this;
}

Set Set::operator+(const Set &other) const {
  Set res = Set(table);
  for (auto i : other.table)
    res += i;
  return res;
}

Set Set::operator+(const int x) const {
  for (auto i : table)
    if (x == i) {
      return Set(table);
    }
  Set res = Set(table);
  res.table.push_back(x);
  return res;
};

Set &Set::operator=(const Set &other) {
  table = other.table;
  return *this;
}

void Set::print() {
  std::cout << "{";
  for (size_t i = 0; i < table.size(); ++i) {
    std::cout << table[i];
    if (i != table.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}" << std::endl;
}

Set operator+(int x, const Set &s) {
  return s + x; // reuse your existing Set + int logic
}
