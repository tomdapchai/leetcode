#include <bits/stdc++.h>
using namespace std;

vector<int> applyOperations(vector<int> &nums)
{
    vector<int> notZero;
    int zero = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {

        if (nums[i] == nums[i + 1])
        {
            nums[i] *= 2;
            notZero.push_back(nums[i]);
            nums[i + 1] = 0;
            continue;
        }
        if (nums[i] == 0)
            zero++;
        else
            notZero.push_back(nums[i]);
    }

    for (int i = 0; i < zero; i++)
    {
        notZero.push_back(0);
    }

    return notZero;
}

int main()
{
    return 0;
}