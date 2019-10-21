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

namespace tsp {

namespace greedy {

using Point = std::pair<int, int>;

int distance(const Point &a, const Point &b) {
  return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

Test RandomGenerator(const TestCase<std::string, int> &case_low) {
  Test test;

  int n = case_low.Get("N");
  test << n << "\n";

  std::vector<std::pair<int, int>> storage;
  for (int i = 0; i < n; ++i) {
    int x = rnd.next(case_low.Get("MIN_X"), case_low.Get("MAX_X"));
    int y = rnd.next(case_low.Get("MIN_Y"), case_low.Get("MAX_Y"));

    storage.emplace_back(x, y);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      test << distance(storage[i], storage[j]);
      if (j != n - 1) {
        test << ' ';
      }
    }
    test << '\n';
  }

  return test;
}

void gen() {
  TestSuite suite;

  // test 1
  TestCase<std::string, int> case_low;
  case_low.Set("N", 20);

  case_low.Set("MIN_X", -1000);
  case_low.Set("MAX_X", 1000);
  case_low.Set("MIN_Y", -1000);
  case_low.Set("MAX_Y", 1000);

  Test result = RandomGenerator(case_low);
  suite.add(result);

  suite.save();
}

}

}

#endif //COMPLEXITY_DIHT_RANDOM_H
