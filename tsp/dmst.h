#pragma once

#include <string>
#include <vector>

#include "../common/testcase.h"
#include "../common/test.h"
#include "../common/testsuite.h"

#include "closure.h"

#include "../common/testlib.h"

namespace tcp {

namespace dmst {

Test GenerateFlowerGr(const TestCase<std::string, int>& test_case) {
  Test result;
  int N = test_case.Get("N");
  int max_edge = test_case.Get("max_edge");
  int head = rnd.next(N);
  result << N << "\n";
  std::vector<std::vector<int>> matrix(N, std::vector<int>(N, 0));
  for (int i = 0; i < N; ++i) {
    if (i != head) {
      matrix[head][i] = matrix[i][head] = rnd.next(max_edge) + 1;
    }
  }
  DoTakeGraphClosure(matrix);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      result << matrix[i][j] << ' ';
      if (j == N - 1) {
        result << '\n';
      }
    }
  }
  return result;
}

void gen() {
  TestSuite suite;

  TestCase<std::string, int> sample_case;
  sample_case.Set("N", 50);
  sample_case.Set("max_edge", 1000);
  suite.add(GenerateFlowerGr(sample_case));

  suite.save();
}

}

}