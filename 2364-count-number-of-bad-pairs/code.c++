#include <bits/stdc++.h>
using namespace std;

unsigned long long combinations(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    if (r > n / 2)
        r = n - r;
    unsigned long long result = 1;
    for (int i = 0; i < r; ++i)
    {
        result = result * (n - i) / (i + 1);
    }
    return result;
}

long long countBadPairs(vector<int> &nums)
{
    unordered_map<int, vector<int>> map; // store nums[i] - i;
    unsigned long long total_pairs = combinations(nums.size(), 2);
    for (int i = 0; i < nums.size(); i++)
    {
        map[i - nums[i]].push_back(i);
    }
    for (const auto &p : map)
    {
        if (p.second.size() > 1)
        {
            unsigned long long tmp_pairs = combinations(p.second.size(), 2);
            total_pairs -= tmp_pairs;
        }
    }
    return total_pairs;
}

int main()
{
    vector<int> nums = {4, 1, 3, 3};
    cout << countBadPairs(nums);
    return 0;
}