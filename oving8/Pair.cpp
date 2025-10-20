#include "Pair.hpp"
#include <iostream>

using namespace std;

void test() {

  Pair<double, int> p1(3.5, 14);
  Pair<double, int> p2(2.1, 7);
  cout << "p1: " << p1.first << ", " << p1.second << endl;
  cout << "p2: " << p2.first << ", " << p2.second << endl;

  if (p1 > p2)
    cout << "p1 er størst" << endl;
  else
    cout << "p2 er størst" << endl;

  auto sum = p1 + p2;
  cout << "Sum: " << sum.first << ", " << sum.second << endl;
}

template <typename T, typename U>
Pair<T, U>::Pair() : first(), second() {}

template <typename T, typename U>
Pair<T, U>::Pair(T f, U s) : first(f), second(s) {}

/**
 * Forutsetter opperasjonene
 * - T + T   -> T
 * - U + U   -> U
 */
template <typename T, typename U>
Pair<T, U> Pair<T, U>::operator+(const Pair &other) const {
  return Pair(first + other.first, second + other.second);
}

/**
 * Forutsetter opperasjonene
 * - T + T   -> X1
 * - U + U   -> X2
 * - X1 > X2 -> bool
 */
template <typename T, typename U>
bool Pair<T, U>::operator>(const Pair &other) const {
  return first + other.first > second + other.second;
}
