#include <vector>
#include <iostream>
#include <iterator>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

void printPair(pair<pair<int, int>, pair<int, int>> pair)
{
    cout << "Pair 1: " << pair.first.first << " " << pair.first.second << endl;
    cout << "Pair 2: " << pair.second.first << " " << pair.second.second << endl;
}

int maxScoreSightseeingPair(vector<int> &values)
{
    int res = 0;
    int maxCurr = values[0] + 0;

    // values[i] + i + values[j] - j

    for (int j = 1; j < values.size(); j++)
    {
        res = max({res, maxCurr + values[j] - j});

        maxCurr = max({maxCurr, values[j] + j});
    }

    return res;
}

int main()
{
    vector<int> values = {2, 7, 7, 2, 1, 7, 10, 4, 3, 3};
    cout << maxScoreSightseeingPair(values);
    return 0;
}