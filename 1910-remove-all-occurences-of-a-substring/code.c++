#include <bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part)
{
    while (s.find(part, 0) != s.npos)
    {
        size_t pos = s.find(part, 0);
        s.erase(pos, part.length());
    }
    return s;
}

int main()
{
    string s = "kpygkivtlqoocskpygkpygkivtlqoocssnextkqzjpycbylkaondskivtlqoocssnextkqzjpycbylkaondssnextkqzjpycbylkaondshijzgaovndkjiiuwjtcpdpbkrfsi";
    string part = "kpygkivtlqoocssnextkqzjpycbylkaonds";
    cout << removeOccurrences(s, part);
    return 0;
}