//
// Created by Алексей Пономарев on 2019-10-21.
//

#ifndef COMPLEXITY_DIHT_GREEDY_H
#define COMPLEXITY_DIHT_GREEDY_H

#include "testlib.h"
#include "../common/testcase.h"

#include <string>

namespace tsp {

namespace greedy {

void RandomGenerator(const TestCase<std::string, int> &case_low) {
  int n = rnd.next(1, case_low.Get("MIN_X"));


}

void gen() {
  TestCase<std::string, int> case_low;
  case_low.Set("MIN_X", -1000);
  case_low.Set("MAX_X", 1000);
  case_low.Set("MIN_Y", -1000);
  case_low.Set("MAX_Y", 1000);

}

}

}

#endif //COMPLEXITY_DIHT_GREEDY_H