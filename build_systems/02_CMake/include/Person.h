// sample class

#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person{
private:
    std::string name;
    int age;
public:
    Person(std::string);
    virtual std::string get_name();
    void one_year_older();
    int get_age();
};

#endif  // PERSON_H_
