//
// Created by hamta on 11/1/2019.
//

#ifndef COMPLEXITY_DIHT_KNAPSACKTESTCASE_H
#define COMPLEXITY_DIHT_KNAPSACKTESTCASE_H

#include <string>
#include <vector>
#include <cmath>

#include "../common/testcase.h"
#include "../common/test.h"
#include "../common/testsuite.h"

#include "../common/testlib.h"

template <class Key, class Value>
class KnapsackTestCase(TestCase) {
public:
    KnapsackTestCase(long long item_count) : _item_count(item_count){};

private:
    int _item_count;
    int ext_val;
};


#endif //COMPLEXITY_DIHT_KNAPSACKTESTCASE_H
