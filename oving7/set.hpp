#pragma once
#include <iostream>
#include <vector>

class Set {
public:
  Set();
  Set(const Set &other);
  Set(std::vector<int>);
  std::vector<int> table;
  Set operator+(const Set &other) const;
  Set operator+(const int) const;
  Set &operator=(const Set &other);
  Set &operator+=(int);
  void print();
};

Set operator+(int x, const Set &s);
