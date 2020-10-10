#include <string>
#include "easylogging++.h"
#include "Person.h"
using namespace std;

Person::Person(string name):name(name), age(0) {}

string Person::get_name(){
  return name;
}

void Person::one_year_older() {
  LOG(INFO) << "Raising "
    << name << "'s  age by a year";
  age += 1;
}

int Person::get_age() {
  return age;
}
