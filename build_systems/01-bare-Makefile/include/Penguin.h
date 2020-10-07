#ifndef PENGUIN_H_
#define PENGUIN_H_

#include <string>

class Penguin {
  private:
    std::string name;
    int age;

  public:
    Penguin(std::string);
    virtual std::string get_name();
    void one_year_older();
    int get_age();
};

#endif  // PENGUIN_H_
