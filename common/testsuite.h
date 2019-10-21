//
// Created by Алексей Пономарев on 2019-10-21.
//

#ifndef COMPLEXITY_DIHT_TESTSUITE_H
#define COMPLEXITY_DIHT_TESTSUITE_H

#include <vector>
#include <string>
#include <fstream>

#include "test.h"

struct TestSuite {
public:
  TestSuite() = default;

  TestSuite(std::string prefix) : _prefix_name(prefix) {}

  void add(const Test &test) {
    _tests.push_back(test);
  }

  void save() {
    int i = 0;
    for (const auto& test : _tests) {
      std::ofstream file("out/" + _prefix_name + std::to_string(i++));
      file << test;
      file.close();
    }
  }

private:
  std::string _prefix_name;
  std::vector<Test> _tests;
};

#endif //COMPLEXITY_DIHT_TESTSUITE_H
