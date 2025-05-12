#include <bits/stdc++.h>
using namespace std;


long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long long sum1 = 0;
    long long sum2 = 0;
    int c1 = 0;
    int c2 = 0;
    for (const int &i : nums1) {
        sum1 += i;
        if (i == 0) c1++;
    }

    for (const int &i : nums2) {
        sum2 += i;
        if (i == 0) c2++;
    }


    if (sum2 == sum1) {
        if (c1 == 0 && c2 == 0) {
            return sum2;
        }
        else if (c1 == 0 || c2 == 0)
            return -1;
        else
            return sum2 + max(c1, c2);
    }

    else if (sum2 > sum1) {
        if (c1 == 0)
            return -1;
        if (c2 == 0) {
            if (sum2 - sum1 < c1)
                return -1;
        }
        if (c2 >= c1)
            return sum2 + c2;
        else {
            int diff = sum2 - sum1;
            if (diff >= c1 - c2) {
                return sum2 + c2;
            }
            else
                return sum1 + c1;

        }
    }
    else {
        if (c2 == 0)
            return -1;
        if (c1 == 0) {
            if (sum1 - sum2 < c2)
                return -1;
        }
        if (c1 >= c2)
            return sum1 + c1;
        else {
            int diff = sum1 - sum2;
            if (diff >= c2 - c1) 
                return sum1 + c1;
            else
                return sum2 + c2;

        }
    }
}

int main() {
    vector<int> nums1 = {8,13,15,18,0,18,0,0,5,20,12,27,3,14,22,0};
    vector<int> nums2 = {29,1,6,0,10,24,27,17,14,13,2,19,2,11};
    long long res = minSum(nums1, nums2);
    cout << res ;


}