#include <bits/stdc++.h>
using namespace std;

bool isArraySpecial(vector<int> &nums)
{
    if (nums.size() < 2)
    {
        return true;
    }
    int curr = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (curr % 2 == nums[i] % 2)
            return false;
        curr = nums[i];
    }
    return true;
}

int main()
{
    return 0;
}