#include <bits/stdc++.h>

using namespace std;

vector<int> pivotArray(vector<int> &nums, int pivot)
{
    vector<int> smaller;
    vector<int> larger;
    vector<int> equal;
    for (const int &i : nums)
    {
        if (i < pivot)
            smaller.push_back(i);
        else if (i == pivot)
            equal.push_back(i);
        else
            larger.push_back(i);
    }

    smaller.insert(smaller.end(), equal.begin(), equal.end());
    smaller.insert(smaller.end(), larger.begin(), larger.end());

    return smaller;
}

int main()
{
    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;
    vector<int> res = pivotArray(nums, pivot);

    for (const int &i : res)
    {
        cout << i << " ";
    }
    return 0;
}