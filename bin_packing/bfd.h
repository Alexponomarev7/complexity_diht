//
// Created by Алексей Пономарев on 2019-10-21.
//

#ifndef COMPLEXITY_DIHT_RANDOM_H
#define COMPLEXITY_DIHT_RANDOM_H

#include <string>
#include <vector>

#include "../common/testcase.h"
#include "../common/test.h"
#include "../common/testsuite.h"

#include "testlib.h"
#include "cassert"

namespace tsp {

namespace random {

Test BfdGenerator(const TestCase<std::string, int> &case_low) {
  Test test;

  int n = case_low.Get("N");
  assert(n % 3 == 0);

  test << n << "\n";

  double k = case_low.Get("K");

  std::vector<double> weights;
  for (int i = 0; i < n / 3; ++i) {
    weights.push_back(k);
    weights.push_back((1 - k) / 2);
    weights.push_back((1 - k) / 2);
  }

  return test;
}

void gen() {
  TestSuite suite("bfd_");

  {
    // test 1
    TestCase<std::string, double> case_low;
    case_low.Set("N", 30);
    case_low.Set("K", 0.4);

    Test result = BfdGenerator(case_low);
    suite.add(result);
  }

  suite.save();
}

}

}

#endif //COMPLEXITY_DIHT_RANDOM_H
