#include <vector>
#include <iostream>
#include <iterator>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int waysToSplitArray(vector<int> &nums)
{
    int n = nums.size();

    long long sum = 0;

    for (int i : nums)
    {
        sum += i;
    }

    long long res = 0, t = 0;

    for (int i = 0; i < n - 1; i++)
    {
        t += nums[i];
        if (t > sum - t)
            res++;
    }

    return res;
}

int main()
{
    vector<int> nums = {10, 4};
    cout << waysToSplitArray(nums);
    return 0;
}