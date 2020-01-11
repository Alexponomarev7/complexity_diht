#pragma once
#include <exception>

// Hello, Floyd-Warshall!
template<typename DataType>
void DoTakeGraphClosure(std::vector<std::vector<DataType>>& matrix) {
  for (size_t middle = 0; middle < matrix.size(); ++middle) {
    for (size_t from = 0; from < matrix.size(); ++from) {
      for (size_t to = 0; to < matrix.size(); ++to) {
        if (from != to) {
          if (matrix[from][to] == 0 || matrix[from][to] > matrix[from][middle] + matrix[middle][to]) {
            matrix[from][to] = matrix[from][middle] + matrix[middle][to];
          }
        }
      }
    }
  }
}
