#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void read_temperatures(double temperatures[], int length);

const char filename[] = "temperatures.dat";
const int length = 5;

int main() {
  double temperatures[length];
  int temperatureIntervalls[3] = {0};

  read_temperatures(temperatures, length);

  for (int i = 0; i < length; i++) {
    if (temperatures[i] < 10)
      temperatureIntervalls[0]++;
    else if (temperatures[i] < 21)
      temperatureIntervalls[1]++;
    else
      temperatureIntervalls[2]++;
  }

  cout << "\nAntall under 10 grader: " << temperatureIntervalls[0] << endl;
  cout << "Antall mellom 10 og 20 (inkludert 10 og 20): " << temperatureIntervalls[1] << endl;
  cout << "Antall 20 eller mer: " << temperatureIntervalls[2] << endl;

  return 0;
}

void read_temperatures(double temperatures[], int length) {

  ifstream file;
  file.open(filename);
  if (!file) {
    cout << "Feil ved åpning av innfil." << endl;
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < length; i++) {

    file >> temperatures[i];
  }

  file.close();
}
