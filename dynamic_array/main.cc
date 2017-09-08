// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <assert.h>
#include <iostream>

#include "vector.h"
#include "test/vector_test.h"

int main(int argc, char *argv[]) {
  jw::JVectorTest tester;
  tester.RunTests();
  std::cout << "Aproved all tests" << std::endl;
  return EXIT_SUCCESS;
}
