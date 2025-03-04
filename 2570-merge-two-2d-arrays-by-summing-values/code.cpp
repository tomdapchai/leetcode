#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
{
    map<int, int> map;

    for (const auto &i : nums1)
    {
        map[i[0]] += i[1];
    }

    for (const auto &i : nums2)
    {
        map[i[0]] += i[1];
    }

    vector<vector<int>> res;

    for (const auto &i : map)
    {
        vector<int> tmp;
        tmp.push_back(i.first);
        tmp.push_back(i.second);
        res.push_back(tmp);
    }

    return res;
}

int main()
{
    return 0;
}