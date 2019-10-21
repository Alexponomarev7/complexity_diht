//
// Created by Алексей Пономарев on 2019-10-21.
//

#ifndef COMPLEXITY_DIHT_GREEDY_H
#define COMPLEXITY_DIHT_GREEDY_H

#include "testlib.h"

#include "../common/testcase.h"
#include "../common/test.h"

#include <string>
#include <vector>

namespace tsp {

namespace greedy {

using Point = std::pair<int, int>;

int distance(const Point &a, const Point &b) {
  return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

// Generate like grid
Test RandomGenerator(const TestCase<std::string, int> &case_low) {
  Test test;

  int n = case_low.Get("N");
  test << n << '\n';

  std::vector<std::pair<int, int>> points;

  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      points.emplace_back(x, y);

      x += case_low.Get("DistanceX");
    }

    x = 0;
    y += case_low.Get("DistanceY");
  }

  shuffle(points.begin(), points.end());

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      test << distance(points[i], points[j]);

      if (i != n - 1) {
        test << ' ';
      }
    }
    test << '\n';
  }

  return test;
}

void gen() {
  TestSuite suite("greedy_");

  {
    // test 1
    TestCase<std::string, int> case_low;
    case_low.Set("N", 5);
    case_low.Set("DistanceX", 895);
    case_low.Set("DistanceY", 579);
    Test result = RandomGenerator(case_low);
    suite.add(result);
  }

  {
    // test 2
    TestCase<std::string, int> case_low;
    case_low.Set("N", 5);
    case_low.Set("DistanceX", 100000);
    case_low.Set("DistanceY", 100000);
    Test result = RandomGenerator(case_low);
    suite.add(result);
  }

  {
    // test 3
    TestCase<std::string, int> case_low;
    case_low.Set("N", 40);
    case_low.Set("DistanceX", 58);
    case_low.Set("DistanceY", 84);
    Test result = RandomGenerator(case_low);
    suite.add(result);
  }

  {
    // test 4
    TestCase<std::string, int> case_low;
    case_low.Set("N", 40);
    case_low.Set("DistanceX", 100);
    case_low.Set("DistanceY", 100);
    Test result = RandomGenerator(case_low);
    suite.add(result);
  }

  suite.save();
}

}

}

#endif //COMPLEXITY_DIHT_GREEDY_H