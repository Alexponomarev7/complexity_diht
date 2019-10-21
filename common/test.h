//
// Created by Алексей Пономарев on 2019-10-21.
//

#ifndef COMPLEXITY_DIHT_TEST_H
#define COMPLEXITY_DIHT_TEST_H

#include <string>
#include <fstream>

struct Test {
public:
  Test() = default;

  Test(std::string in) : _in(in), _is_set(false) {
  }

  Test(std::string in, std::string out) : _in(in), _out(out), _is_set(true) {
  }

  friend std::ostream& operator<<(std::ostream& s, const Test& test) {
    s << test._in;
    return s;
  }

  template <class T>
  Test& operator<<(const T& obj) {
    std::stringstream ss;
    ss << obj;

    _in += ss.str();
    return *this;
  }

private:
  std::string _in;
  bool _is_set;
  std::string _out;
};

#endif //COMPLEXITY_DIHT_TEST_H
