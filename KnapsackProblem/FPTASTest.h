//
// Created by hamta on 1/12/2020.
//

#ifndef COMPLEXITY_DIHT_FPTASTEST_H
#define COMPLEXITY_DIHT_FPTASTEST_H

#endif //COMPLEXITY_DIHT_FPTASTEST_H

#include <string>
#include <vector>
#include <cmath>

#include "../common/testcase.h"
#include "../common/test.h"
#include "../common/testsuite.h"
#include "KnapsackSolver.h.h"

#include "../common/testlib.h"

template <class Key, class Value>
Test generate_simple_FPTAS_test(const KnapsackTestCase<Key, Value>& test_case_data) {
    Test test;

    long long n = 4;
    long long knapsack_capacity = 5;
    std::vector<double> weights{2, 4, 1, 2};
    std::vector<long long> costs{4, 7,5, 12, 4};

    for (int i = 0; i < n; ++i) {
        test << weights[i];

        if (i != n - 1)
            test << ' ';
    }

    test << '\n';

    for (int i = 0; i < n; ++i) {
        test << costs[i];

        if (i != n - 1)
            test << ' ';
    }

    test << '\n';

    answer = solve_knapsack(weights, costs, knapsack_capacity);
    test << answer;
};

void make_suite(){
    TestSuite suite("knapsack_FPTAS");

    TestCase<std::string, int> test_case_data;
    Test result = generate_simple_FPTAS_test(test_case_data);
    suite.add(result);

    suite.save();
}

#endif //COMPLEXITY_DIHT_RANDOMTEST_H
