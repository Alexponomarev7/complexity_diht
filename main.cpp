#include <iostream>

#include "tsp/testlib.h"
#include "tsp/random.h"
#include "tsp/chr.h"
#include "tsp/dmst.h"

int main() {
  tsp::chr::gen();
  tsp::random::gen();

  return 0;
}