#include "Pair.hpp"
#include <iostream>

using namespace std;

// oppgave 1
template <typename Type>
bool equal(Type a, Type b) {
  cout << "bruker template-funksjonen" << endl;
  return a == b;
}

template <>
bool equal(double a, double b) {
  cout << "bruker double-spesialisering" << endl;
  return abs(a - b) < 0.00001;
}

int main() {

  // tester oppgave 1
  cout << "Oppgave 1:" << endl;
  char a = 'a';
  char b = 'a';
  cout << equal(a, b) << endl;
  cout << equal(2.000001, 2.0) << endl;
  cout << " " << endl;

  // tester oppgave 2
  cout << "Oppgave 2:" << endl;
  test();
}
