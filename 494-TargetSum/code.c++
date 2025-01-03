#include <vector>
#include <iostream>
#include <iterator>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

// calculate how many ways to get target + nums[i], target - nums[i]

// dp[i][target]

// 2D DP
int helper(int i, vector<int> &nums, int target, int sum, vector<unordered_map<int, int>> &dp)
{
    if (i == 0)
    {
        if (nums[0] == 0 && target == 0)
            return 2;
        return (nums[0] == target) || (-nums[0] == target);
    }

    if (abs(sum) < abs(target))
        return 0;

    if (dp[i].find(target) != dp[i].end())
    {
        return dp[i][target];
    }

    dp[i][target] = helper(i - 1, nums, target - nums[i], sum - nums[i], dp) + helper(i - 1, nums, target + nums[i], sum - nums[i], dp);

    return dp[i][target];
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int sum = 0;

    if (n == 1)
        return (nums[0] == target) || (-nums[0] == target);

    for (int i : nums)
    {
        sum += i;
    }

    vector<unordered_map<int, int>> dp(n);

    int res = helper(n - 1, nums, target, sum, dp);

    /* for (int i = 0; i < n; ++i)
    {
        cout << "dp[" << i << "]:" << endl;
        for (const auto &[target, value] : dp[i])
        {
            cout << "  target = " << target << ", ways = " << value << endl;
        }
    } */

    return res;
}

int main()
{
    vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    int target = 1;

    cout << findTargetSumWays(nums, target);
    return 0;
}
