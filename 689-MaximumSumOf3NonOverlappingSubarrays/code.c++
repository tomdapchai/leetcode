#include <vector>
#include <iostream>
#include <iterator>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
{

    // store 3 pairs (sum, index) of sub array, and the smallest sum index, 2nd smallest sum index of this
    pair<vector<pair<int, int>>, pair<int, int>> store;

    int sum = 0; // act like sum of vector window size k
    for (int i = 0; i < k; i++)
        sum += nums[i];

    for (int i = 1; i < nums.size() - k; i++)
    {
        sum = sum - nums[i - 1] + nums[i + k - 1];
        if (sum > store.first[store.second.first].first)
        {
            // check overlap, usually only for the last place
            if ((i - k + 1 <= store.first[2].second && store.first[2].second < i) && (store.second.first != store.first[2].second))
            {
                // if sum < store.first[2].first do nothing
                if (sum <= store.first[2].first)
                    continue;
                // else, replace the store.first[2], by (sum, i), but that also leads to a possiblity that other pairs currently in the store isnt correct any more
            }

            else
            {
                store.first[store.second.first].first = sum;
                store.first[store.second.first].second = i;
            }

            // replace it first, then swap

            // done checking and assigning stuffs
            sort(store.first.begin(), store.first.end(), [](pair<int, int> &a, pair<int, int> &b)
                 { return a.second < b.second; });

            // reset the according position of smallest and 2nd smallest sum

            vector<pair<int, int>> tmp(store.first.begin(), store.first.end());
            sort(tmp.begin(), tmp.end(), [](pair<int, int> &a, pair<int, int> &b)
                 { return a.first < b.first; });

            store.second = {tmp[0].second, tmp[1].second};
        }
    }

    vector<int> res;
    for (pair<int, int> p : store.first)
    {
        res.push_back(p.second);
    }

    return res;
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 6, 7, 5, 1};
    int k = 2;
    vector<int> res = maxSumOfThreeSubarrays(nums, k);

    for (int i : res)
    {
        cout << i << " ";
    }
    return 0;
}