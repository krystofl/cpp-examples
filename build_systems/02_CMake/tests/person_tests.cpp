#include <string>
#include "easylogging++.h"
#include "Person.h"
#include "gtest/gtest.h"


INITIALIZE_EASYLOGGINGPP

namespace {
  TEST(PersonTest, Name) {
    std::string name = "Adelie";
    Person a(name);
    EXPECT_EQ(a.get_name(), name);
  }

  TEST(PersonTest, Age) {
    Person p("Bob");
    EXPECT_EQ(p.get_age(), 0);

    p.one_year_older();
    EXPECT_EQ(p.get_age(), 1);
  }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    START_EASYLOGGINGPP(argc, argv);

    return RUN_ALL_TESTS();
}
