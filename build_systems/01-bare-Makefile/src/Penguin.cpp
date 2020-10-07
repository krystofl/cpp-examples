#include <string>
#include "Penguin.h"

using namespace std;

Penguin::Penguin(string name):name(name), age(0) {}

string Penguin::get_name(){
  return name;
}

void Penguin::one_year_older() {
  age += 1;
}

int Penguin::get_age() {
  return age;
}
