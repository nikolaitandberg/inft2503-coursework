#pragma once
#include <string>

using namespace std;

class Commodity {
private:
  string name;
  int id;
  double price;

public:
  Commodity(string name_, int id_, double price_);
  string get_name() const;
  int get_id() const;
  double get_price() const;
  double get_price(int quantity) const;
  double get_price_with_sales_tax(int quantity) const;
  void set_price(double new_price);
};

void testCommodity();
