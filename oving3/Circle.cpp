#include "Circle.hpp"
#include <iostream>

using namespace std;
const double pi = 3.141592;

Circle::Circle(double radius_) : radius(radius_) {}

int Circle::get_area() const {
  return pi * radius * radius;
}

double Circle::get_circumference() const {
  double circumference = 2.0 * pi * radius;
  return circumference;
}

void testCircle() {
  Circle circle(5);

  int area = circle.get_area();
  cout << "Arealet er lik " << area << endl;

  double circumference = circle.get_circumference();
  cout << "Omkretsen er lik " << circumference << endl;
}
