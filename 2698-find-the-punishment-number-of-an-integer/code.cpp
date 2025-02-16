#include <bits/stdc++.h>
using namespace std;

bool check(int n, string str)
{
    if (stoi(str) == n)
        return true;
    for (int i = 1; i < str.length(); i++)
    {
        string headStr = str.substr(0, i);
        if (check(n - stoi(headStr), str.substr(headStr.length())))
            return true;
    }

    return false;
}

int punishmentNumber(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (check(i, to_string(i * i)))
            sum += i * i;
    }
    return sum;
}

int main()
{
    cout << punishmentNumber(10);
    return 0;
}