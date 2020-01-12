//
// Created by hamta on 1/12/2020.
//

#ifndef COMPLEXITY_DIHT_DOMINANCETEST_H
#define COMPLEXITY_DIHT_DOMINANCETEST_H

#endif //COMPLEXITY_DIHT_DOMINANCETEST_H

#include <string>
#include <vector>
#include <cmath>

#include "../common/testcase.h"
#include "../common/test.h"
#include "../common/testsuite.h"
#include "KnapsackSolver.h"

#include "../common/testlib.h"

namespace knapsack_dominance {
    template<class Key, class Value>
    Test generate_simple_dominance_test(const TestCase<Key, Value> &test_case_data) {
        Test test;

        long long n = rand() % 1000 + 3;
        long long all_weight = 0;
        long long all_cost = 0;
        std::vector<long long> weights(n);
        std::vector<long long> costs(n);

        for (int i = 0; i < n - 1; ++i) {
            weights[i] = rand();
            weights[i] += weights[i] == 0 ? 1 : 0;
            all_weight += weights[i];

            test << weights[i];
            test << ' ';
        }

        weights[n - 1] = all_weight + rand() % 100 + 1;
        all_weight += weights[n - 1];
        long long knapsack_capacity = all_weight;

        test << weights[n - 1] << ' ';
        test << '\n';

        for (int i = 0; i < n - 1; ++i) {
            costs[i] = rand();
            all_cost += costs[i];

            test << costs[i];
            test << ' ';
        }

        costs[n - 1] = std::max(int(all_cost - 1), 1);

        test << costs[n - 1] << ' ';
        test << '\n';

        long long answer = solve_knapsack(weights, costs, knapsack_capacity);
        test << answer;
    };

    void make_suite() {
        TestSuite suite("knapsack_dominance");

        for (int i = 0; i < 10; ++i) {
            // test 1
            TestCase<std::string, int> test_case_data;
            Test result = generate_simple_dominance_test(test_case_data);
            suite.add(result);
        }

        suite.save();
    }
}
