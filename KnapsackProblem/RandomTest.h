//
// Created by hamta on 11/1/2019.
//

#include <string>
#include <vector>
#include <cmath>

#include "../common/testcase.h"
#include "../common/test.h"
#include "../common/testsuite.h"
#include "KnapsackSolver.h"

#include "../common/testlib.h"

namespace knapsack_random {
    template<class Key, class Value>
    Test generate_random_test(const TestCase<Key, Value> &test_case_data) {
        Test test;

        long long n = rand() % 10000;
        long long knapsack_capacity = rand();
        std::vector<long long> weights(n);
        std::vector<long long> costs(n);

        for (int i = 0; i < n; ++i) {
            weights[i] = rand();
            weights[i] += weights[i] == 0 ? 1 : 0;

            test << weights[i];

            if (i != n - 1)
                test << ' ';
        }

        test << '\n';

        for (int i = 0; i < n; ++i) {
            costs[i] = rand();
            test << costs[i];

            if (i != n - 1)
                test << ' ';
        }

        test << '\n';

        long long answer = solve_knapsack(weights, costs, knapsack_capacity);
        test << answer;
    };

    void make_suite() {
        TestSuite suite("knapsack_random");

        for (int i = 0; i < rand() % 5 + 1; ++i) {
            TestCase<std::string, int> test_case_data;
            Test result = generate_random_test(test_case_data);
            suite.add(result);
        }

        suite.save();
    }
}
