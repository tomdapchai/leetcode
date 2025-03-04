#include <bits/stdc++.h>
using namespace std;

int logCustomBase(int n, int base)
{
    return log10(n) / log10(base);
}

bool checkPowersOfThree(int n)
{
    if (n == 2)
        return false;
    if (n == 0)
        return true;
    if (n >= (2 * pow(3, logCustomBase(n, 3))))
        return false;

    return checkPowersOfThree(n - pow(3, logCustomBase(n, 3)));
}

int main()
{
    return 0;
}