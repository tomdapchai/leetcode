#include <vector>
#include <iostream>
#include <iterator>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isVowel(string s)
{
    if (s.length() == 0)
        return false;
    if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') && (s[s.length() - 1] == 'a' || s[s.length() - 1] == 'e' || s[s.length() - 1] == 'i' || s[s.length() - 1] == 'o' || s[s.length() - 1] == 'u'))
        return true;
    return false;
}

vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
{
    // Prefix sum
    vector<int> res;
    vector<int> pf(words.size());
    pf[0] = isVowel(words[0]);
    for (int i = 1; i < words.size(); i++)
        pf[i] = isVowel(words[i]) + pf[i - 1];

    for (vector<int> q : queries)
    {
        int l = q[0], r = q[1];

        if (l == 0)
            res.push_back(pf[r]);
        else
            res.push_back(pf[r] - pf[l - 1]);
    }

    return res;
}

int main()
{
    return 0;
}