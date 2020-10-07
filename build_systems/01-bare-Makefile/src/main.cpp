#include <iostream>

#include "Penguin.h"

using namespace std;

int main(int argc, char *[])
{
  Penguin Bob("Bob");
  Bob.one_year_older();
  Bob.one_year_older();

  cout << "Penguin " << Bob.get_name() << " is "
       << Bob.get_age() << " years old.\n";

  return 0;
}
