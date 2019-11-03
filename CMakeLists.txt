cmake_minimum_required(VERSION 3.14)
project(complexity_diht)

set(CMAKE_CXX_STANDARD 14)

add_executable(complexity_diht main.cpp tsp/greedy.h tsp/chr.h tsp/dmst.h tsp/random.h common/test.h algorithm/greedy.h common/testcase.h common/testsuite.h tsp/validator.h knapsack_problem/RandomTest.cpp knapsack_problem/RandomTest.h knapsack_problem/KnapsackTestCase.cpp knapsack_problem/KnapsackTestCase.h)