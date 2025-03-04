#include <bits/stdc++.h>
using namespace std;

/* string help(string s)
{

    return s;
} */

int numDecodings(string s)
{
    auto removeZero = [&](string &s, bool &c)
    {
        for (int i = 0; i < s.length() - 1; i++)
        {
            int tmpI = i;
            while (tmpI < s.length() - 1 && s[tmpI] == '0' && s[tmpI + 1] == '0')
            {
                tmpI++;
                c = false;
                break;
            }
            /* if (tmpI == s.length() - 1 && i > 0)
            {
                if (s[i - 1] == '1' || s[i - 1] == '2')
                    s.erase(i, tmpI - i);
                else
                    s.erase(i, tmpI - i + 1);
            }
            else
                s.erase(i, tmpI - i); */
        }
    };

    auto valid = [&](char c1, char c2)
    {
        return stoi(string(1, c1) + c2) >= 10 && stoi(string(1, c1) + c2) <= 26;
    };
    bool c = true;
    removeZero(s, c);
    if (!c)
        return 0;

    cout << s << endl;
    int n = s.size();
    vector<int> ways(n, 0); // dp
    bool check = true;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            ways[i] = ways[i - 1];

        if (s[i] == '0')
            check = false;

        if (i > 0 && valid(s[i - 1], s[i]))
        {
            if (s[i] != '0' || (i > 1 && s[i - 2] == '0') || (i == 1))
            {
                ways[i]++;
                if (i > 2 && valid(s[i - 3], s[i - 2]) && s[i - 2] != '0')
                {
                    ways[i]++;
                }
            }
        }
        if (s[i] == '0' && i > 0 && !valid(s[i - 1], s[i]))
        {
            ways[i]--;
        }
    }

    return ways[n - 1] + check;
}

int main()
{
    string s = "123123";
    cout << numDecodings(s);
    return 0;
}