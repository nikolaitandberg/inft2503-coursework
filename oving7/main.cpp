#include "fraction.hpp"
#include "set.hpp"
#include <iostream>

using namespace std;

int main() {

  // oppgave 1
  Fraction fraction1(1, 4);

  Fraction fraction2 = fraction1 - 5;

  Fraction fraction3 = 5 - fraction1;

  cout << "fraction1: " << fraction1.numerator << " / " << fraction1.denominator << endl;
  cout << "fraction1 - 5: " << fraction2.numerator << " / " << fraction2.denominator << endl;
  cout << "5 - fraction1: " << fraction3.numerator << " / " << fraction3.denominator << endl;

  cout << "fraction1: " << fraction1.numerator << " / " << fraction1.denominator << endl;

  // oppgave 2

  Set a({1, 2, 3}), b({3, 4, 5});
  std::cout << "a: ";
  a.print();
  std::cout << "b: ";
  b.print();

  Set c = a + b;
  std::cout << "c = a + b: ";
  c.print();

  Set d = c + 6;
  std::cout << "d = c + 6: ";
  d.print();

  Set e = 7 + d;
  std::cout << "e = 7 + d: ";
  e.print();

  Set f = e + 3;
  std::cout << "f = e + 3: ";
  f.print();

  Set g = f;
  std::cout << "g = f: ";
  g.print();

  return 0;
}
