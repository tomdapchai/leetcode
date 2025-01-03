#include <vector>
#include <iostream>
#include <iterator>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

int help(int n, vector<int> &pre, vector<int> &cost)
{
    if (pre[n] != -1)
    {
        return pre[n];
    }

    pre[n] = min({cost[n] + help(n - 1, pre, cost), cost[n] + help(n - 2, pre, cost)});

    return min(pre[n], pre[n - 1]);
}

int minCostClimbingStairs(vector<int> &cost)
{

    int n = cost.size();
    if (n == 2)
    {
        return min(cost[0], cost[1]);
    }

    vector<int> pre(n, -1);
    pre[0] = cost[0];
    pre[1] = cost[1];
    return help(n - 1, pre, cost);
}

int main()
{
    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost);
    return 0;
}