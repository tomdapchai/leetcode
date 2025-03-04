#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &n, vector<pair<int, int>> &map, int k, int index, vector<int> &left, vector<int> &res)
{
    // if res already have one, then auto eliminate all other tries as it won't be a better result
    if (res[0] != 0)
    {
        vector<int> tmp = n;
        tmp[index] = k;
        if (!lexicographical_compare(res.begin(), res.end(), tmp.begin(), tmp.end()))
            return false;
    }
    // check first
    if (map[k - 1].first != -1)
    {
        if (index - map[k - 1].first != k)
            return false;
        if (index == n.size() - 1) // match all
        {
            n[index] = k;

            if (lexicographical_compare(res.begin(), res.end(), n.begin(), n.end()))
                res = n;
            return true;
        }

        map[k - 1].second = index;
    }
    else
    {
        if (k == 1 && index == n.size() - 1)
        {
            n[index] = k;
            if (lexicographical_compare(res.begin(), res.end(), n.begin(), n.end()))
                res = n;
            return true;
        }
        map[k - 1].first = index;
    }

    n[index] = k;

    bool valid = false;
    for (int i = 0; i < left.size(); i++)
    {
        vector<int> tmp = left;
        tmp.erase(tmp.begin() + i);
        if (check(n, map, left[i], index + 1, tmp, res))
            valid = true;
    }

    // undo backtrack
    n[index] = 0;
    if (map[k - 1].second != -1)
        map[k - 1].second = -1;
    else
        map[k - 1].first = -1;

    return valid;
}

vector<int> constructDistancedSequence(int n)
{
    vector<int> res(2 * n - 1, 0);
    vector<int> init;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            init.push_back(1);
        else
        {
            init.push_back(i);
            init.push_back(i);
        }
    }

    for (int i = 0; i < init.size(); i++)
    {
        vector<int> tmp(2 * n - 1, 0);
        vector<pair<int, int>> map(n, {-1, -1});
        vector<int> left = init;
        left.erase(left.begin() + i);
        check(tmp, map, init[i], 0, left, res);
    }
    return res;
}

int main()
{
    vector<int> nums = constructDistancedSequence(20);
    for (const auto &i : nums)
    {
        /* for (const auto &t : i)
            cout << t << " ";
        cout << endl; */
        cout << i << " ";
    }
    return 0;
}