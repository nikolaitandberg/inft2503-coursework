#pragma once

void test();

template <typename T, typename U>
class Pair {
public:
  T first;
  U second;

  Pair();
  Pair(T, U);

  Pair operator+(const Pair &other) const;
  bool operator>(const Pair &other) const;
};
