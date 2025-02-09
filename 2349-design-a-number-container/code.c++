#include <bits/stdc++.h>
using namespace std;

class NumberContainers
{
private:
    unordered_map<int, set<int>> indexes; // [value, [indexes]]
    unordered_map<int, int> nums;         // [index, value]

public:
    NumberContainers() {}

    /* NumberContainers(vector<int> nums)
    {
        this->nums = nums;
        for (int i = 0; i < this->nums.size(); i++)
        {
            indexes[this->nums[i]].insert(i);
        }
    } */

    void change(int index, int number)
    {
        if (!indexes[number].count(index))
        {
            if (nums[index] != 0)
            { // means there is prev value
                indexes[nums[index]].erase(index);
                nums[index] = number;
            }
            else
            { // mean there is no prev value for this index
                nums[index] = number;
            }
            indexes[number].insert(index);
        }
    }

    int find(int number)
    {
        if (indexes[number].size() > 0)
        {
            return *indexes[number].begin();
        }
        else
            return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
int main()
{
    NumberContainers *obj = new NumberContainers();
    obj->change(1, 20);
    obj->change(1, 30);
    obj->change(1, 20);
    int param_2 = obj->find(30);
    cout << param_2;
    return 0;
}