//
// Created by hamta on 1/11/2020.
//

#ifndef COMPLEXITY_DIHT_KNAPSACKSOLVER_H
#define COMPLEXITY_DIHT_KNAPSACKSOLVER_H

#endif //COMPLEXITY_DIHT_KNAPSACKSOLVER_H

#include <vector>
#include <limits>

//wts - массив весов, cost - массив стоимостей предметов, W - вместимость рюкзака
//функция возвращает максимальную стоимость, которую можно набрать(решение задачи о рюкзаке
//с повторениями)
//массив dp собственно реализует динамическое программирование, описанное в статье, как K_w
int solve_knapsack(const std::vector<int>& wts, const std::vector<int>& cost, int W)
{
    size_t n = wts.size();
    std::vector<int> dp(W + 1);
    dp[0] = 0;
    for (int w = 1; w <= W; w++)
    {
        dp[w] = dp[w-1];
        for (size_t i = 0; i < n; i++)
        {
            if (wts[i] <= w)
            {
                dp[w] = std::max(dp[w], dp[w - wts[i]] + cost[i]);
            }
        }
    }
    return dp[W];
}