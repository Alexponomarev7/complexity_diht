//
// Created by hamta on 1/11/2020.
//

#ifndef COMPLEXITY_DIHT_GREEDYTEST_H
#define COMPLEXITY_DIHT_GREEDYTEST_H

#endif //COMPLEXITY_DIHT_GREEDYTEST_H

#include <string>
#include <vector>
#include <cmath>

#include "../common/testcase.h"
#include "../common/test.h"
#include "../common/testsuite.h"
#include "../common/testlib.h"
#include "KnapsackSolver.h"

namespace knapsack_greedy {
    template<class Key, class Value>
    Test generate_simple_greedy_test(const TestCase<Key, Value> &test_case_data) {
        Test test;

        long long n = 3;
        long long knapsack_capacity = 6;
        std::vector<long long> weights = {4, 3, 3};
        std::vector<long long> costs = {8, 5, 5};

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

        long long answer = solve_knapsack(weights, costs, knapsack_capacity);
        test << answer;
    };

    void make_suite() {
        TestSuite suite("knapsack_greedy");

        TestCase<std::string, int> test_case_data;
        Test result = generate_simple_greedy_test(test_case_data);
        suite.add(result);

        suite.save();
    }
}
