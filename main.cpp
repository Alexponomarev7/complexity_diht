#include <iostream>

#include "tsp/testlib.h"
#include "tsp/random.h"
#include "tsp/chr.h"
#include "tsp/dmst.h"
#include "tsp/greedy.h"

int main() {
  tsp::chr::gen();
  tsp::random::gen();
  tsp::greedy::gen();

  return 0;
}