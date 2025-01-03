#include <vector>
#include <iostream>
#include <iterator>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

long long help(int n, vector<long long> &sum)
{
    if (sum[n] != 0)
    {
        return sum[n];
    }
    cout << n << " " << sum[n] << endl;

    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    sum[n] = help(n - 1, sum) + help(n - 2, sum);

    return sum[n];
}

long long climbStairs(int n)
{
    vector<long long> sum(n + 1);
    return help(n, sum);
}

int main()
{
    cout << climbStairs(35);
    return 0;
}