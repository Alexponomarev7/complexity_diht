#include <iostream>

#include "common/testlib.h"
#include "tsp/random.h"
#include "tsp/chr.h"
#include "tsp/dmst.h"
#include "tsp/greedy.h"
#include "KnapsackProblem/RandomTest.h"
#include "KnapsackProblem/GreedyTest.h"
#include "KnapsackProblem/DominanceTest.h"
#include "KnapsackProblem/FPTASTest.h"

int main() {
  // Register tests
  tsp::chr::gen();
  tsp::random::gen();
  tsp::greedy::gen();
  tsp::dmst::gen();

  // Benchmarks
  // ...

  // Solution
  // ...

  // Execute
  // ...

  return 0;
}