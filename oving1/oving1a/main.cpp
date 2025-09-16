#include <iostream>
#include <vector>

using namespace std;

const int length = 5;
int under10, under21, over21;
double temp1, temp2, temp3, temp4, temp5;

int main() {

  vector<int> temps;

  cout << "Skriv inn" << length << "temperaturer:\n";
  cout << "temperatur 1: ";
  cin >> temp1;
  cout << "temperatur 2: ";
  cin >> temp2;
  cout << "temperatur 3: ";
  cin >> temp3;
  cout << "temperatur 4: ";
  cin >> temp4;
  cout << "temperatur 5: ";
  cin >> temp5;

  if (temp1 < 10)
    under10++;
  else if (temp1 < 21)
    under21++;
  else
    over21++;

  if (temp2 < 10)
    under10++;
  else if (temp2 < 21)
    under21++;
  else
    over21++;

  if (temp3 < 10)
    under10++;
  else if (temp3 < 21)
    under21++;
  else
    over21++;

  if (temp4 < 10)
    under10++;
  else if (temp4 < 21)
    under21++;
  else
    over21++;

  if (temp5 < 10)
    under10++;
  else if (temp5 < 21)
    under21++;
  else
    over21++;

  cout << "\nAntall under 10 grader: " << under10 << endl;
  cout << "Antall mellom 10 og 20 (inkludert 10 og 20): " << under21 << endl;
  cout << "Antall 20 eller mer: " << over21 << endl;

  return 0;
}
