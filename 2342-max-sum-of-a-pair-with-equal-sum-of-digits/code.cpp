#include <bits/stdc++.h>
using namespace std;

int maximumSum(vector<int> &nums)
{
    auto digitSumCount = [&](long long num)
    {
        int res = 0;
        while (num > 0)
        {
            res += num % 10;
            num /= 10;
        }
        return res;
    };

    // ascending
    auto cmp = [&](pair<int, int> &p, int value)
    {
        if (value > p.first)
            p.first = value;
        if (p.first > p.second)
            swap(p.first, p.second);
    };

    unordered_map<int, pair<int, int>> indexes;
    for (const int &i : nums)
    {
        int tmp = digitSumCount(i);
        cmp(indexes[tmp], i);
    }

    bool check = false;
    int res = 0;

    for (const auto &p : indexes)
    {
        if (p.second.first && p.second.second)
        {
            check = true;
            int tmp = p.second.first + p.second.second;
            if (tmp > res)
                res = tmp;
        }
    }
    if (!check)
        return -1;
    return res;
}

int main()
{
    vector<int> nums = {229, 398, 269, 317, 420, 464, 491, 218, 439, 153, 482, 169, 411, 93, 147, 50, 347, 210, 251, 366, 401};
    cout << maximumSum(nums) << endl;
    return 0;
}