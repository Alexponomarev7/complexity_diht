//
// Created by Алексей Пономарев on 2019-10-21.
//

#ifndef COMPLEXITY_DIHT_TESTCASE_H
#define COMPLEXITY_DIHT_TESTCASE_H

#include <unordered_map>
#include <string>

template <class Key, class Value>
struct TestCase {
private:
  using KeyValue = std::unordered_map<Key, Value>;

public:
  TestCase() = default;

  TestCase(KeyValue values) : _values(values) {}

  void Set(const Key &key, const Value &value) {
    _values[key] = value;
  }

  Value Get(const Key &key) const {
    return _values.at(key);
  }

private:

  KeyValue _values;
};

#endif //COMPLEXITY_DIHT_TESTCASE_H
