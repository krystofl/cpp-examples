#include <iostream>

#include "easylogging++.h"

#include "Person.h"

INITIALIZE_EASYLOGGINGPP



int object_test()
{
  Person p("Bob");

  LOG(INFO) << "Hello from " << p.get_name();
  return 0;
}



int easylogging_test()
{
  // load config file
  el::Configurations conf("../config/easylogging.conf");

  // make all loggers use this config
  el::Loggers::reconfigureAllLoggers(conf);

  LOG(INFO)  << "Running easylogging_test()";
  LOG(DEBUG) << "This is a debug message";

  return 0;
}


int main(int argc, char *argv[])
{
  START_EASYLOGGINGPP(argc, argv);
  easylogging_test();

  object_test();

  return 0;
}
