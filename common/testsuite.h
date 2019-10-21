//
// Created by Алексей Пономарев on 2019-10-21.
//

#ifndef COMPLEXITY_DIHT_TESTSUITE_H
#define COMPLEXITY_DIHT_TESTSUITE_H

#include <vector>
#include "test.h"

struct TestSuite {
public:
  TestSuite() = default;

  void add(const Test &test) {
    _tests.push_back(test);
  }

  void save() {}

private:
  std::vector<Test> _tests;
};

#endif //COMPLEXITY_DIHT_TESTSUITE_H
