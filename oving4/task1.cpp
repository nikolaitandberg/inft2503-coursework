#include "task1.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void task1() {
  vector<double> vec;

  vec.push_back(1.1);
  vec.push_back(2.2);
  vec.push_back(3.3);
  vec.push_back(4.4);
  vec.push_back(5.5);

  cout << vec.front() << "\n";
  cout << vec.back() << "\n";

  vec.emplace(vec.begin() + 1, 100.100);

  cout << vec.front() << "\n";

  auto it = find(vec.begin(), vec.end(), 100.100);

  if (it != vec.end()) {
    cout << "vellykket: " << *it << endl;
  } else {
    cout << "Ikke vellykket" << endl;
  }
}
