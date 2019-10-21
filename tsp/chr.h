#pragma once

#include <string>
#include <vector>
#include <cmath>

#include "../common/testcase.h"
#include "../common/test.h"
#include "../common/testsuite.h"

#include "testlib.h"

namespace tsp {

namespace chr {

Test ChrGenerator(const TestCase<std::string, int> &case_low) {
  Test test;

  int n = case_low.Get("N");
  test << n << "\n";

  std::vector<int> edges(n - 1), sums(n);
  for (int i = 0; i < n - 1; ++i) {
    edges[i] = rnd.next(1, case_low.Get("MaxSize"));
    sums[i + 1] = sums[i] + edges[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (std::min(i, j) == 0 && std::max(i, j) == n - 1) {
        test << case_low.Get("ExtremalValue");
      }

      if (abs(i - j) == 1) {
        test << edges[std::min(i, j)];
      } else {
        test << sums[std::max(i, j) + 1] - sums[std::min(i, j)] + 1;
      }

      if (j != n - 1) {
        test << ' ';
      }
    }
    test << '\n';
  }

  return test;
}

void gen() {
  TestSuite suite("chr_");

  {
    // test 1
    TestCase<std::string, int> case_low;
    case_low.Set("N", 20);
    case_low.Set("MaxSize", 1000);
    case_low.Set("ExtremalValue", 1000000000);
    Test result = ChrGenerator(case_low);
    suite.add(result);
  }

  {
    // test 2
    TestCase<std::string, int> case_low;
    case_low.Set("N", 20);
    case_low.Set("MaxSize", 1000000);
    case_low.Set("ExtremalValue", 1000000000);
    Test result = ChrGenerator(case_low);
    suite.add(result);
  }

  {
    // test 3
    TestCase<std::string, int> case_low;
    case_low.Set("N", 1000);
    case_low.Set("MaxSize", 1000);
    case_low.Set("ExtremalValue", 1000000000);
    Test result = ChrGenerator(case_low);
    suite.add(result);
  }

  {
    // test 4
    TestCase<std::string, int> case_low;
    case_low.Set("N", 1000);
    case_low.Set("MaxSize", 1000000);
    case_low.Set("ExtremalValue", 1000000000);
    Test result = ChrGenerator(case_low);
    suite.add(result);
  }

  suite.save();
}

}

}