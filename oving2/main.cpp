#include <cstring>
#include <iostream>
#include <set>
using namespace std;

void oppgave1() {
  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  cout << &i << " inneholder " << i << endl;
  cout << &j << " inneholder " << j << endl;
  cout << &p << " inneholder " << p << endl;
  cout << &q << " inneholder " << q << endl;

  *p = 7;
  *q += 4;
  *q = *p + 1;
  p = q;

  cout << *p << " " << *q << endl;
}

void oppgave3() {
  char text[5];

  char *pointer = text;

  char search_for = 'e';

  cin >> text;

  while (*pointer != search_for) {
    *pointer = search_for;
    cout << *pointer << endl;
    pointer++;
    cout << pointer << endl;
  }
}

void oppgave4() {
  /* kode med feil:
  int a = 5;
  int &b; // b blir deklarert men ikke initialisert, en referanse må referere til noe
  int *c;
  c = &b;
  *a = *b + *c; // a er en int og ikke en peker, får derfor feil når man forsøker å bruke dereference-operatoren på variabelen a
  &b = 2; // etter en referanse har blitt initialisert kan den ikke bli gjort om til å referere til noe annet.
  */

  // Etter feil har blitt fikset:
  int a = 5;
  int &b = a;
  int *c;
  c = &b;
  a = b + *c;
}

void oppgave5() {
  double number;
  double *ptr = &number;
  double &ref = number;

  number = 10;            // tilordner med variablen selv
  cout << number << endl; // utskriften burde være 10

  *ptr = 11;              // tilordner med pekeren
  cout << number << endl; // utskriften burde være 11

  ref = 12;               // tilordner med referansen
  cout << number << endl; // utskriften burde være 12
}

int find_sum(const int *table, int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += table[i];
  }
  return sum;
}

void oppgave6() {

  int table[20];
  for (int i = 0; i < 20; i++) {
    table[i] = i + 1;
  }

  int foerste10 = find_sum(table, 10);
  int neste5 = find_sum(table + 10, 5);
  int siste5 = find_sum(table + 15, 5);

  cout << foerste10 << endl;
  cout << neste5 << endl;
  cout << siste5 << endl;
}

int main() {

  // oppgave1();
  // oppgave4();
  // oppgave5();
  oppgave6();

  return 1;
}
