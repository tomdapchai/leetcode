#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers
{
private:
    vector<int> nums{};
    int noZero = 0;

public:
    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        if (num != 0)
        {
            if (num != 0 && nums.size() > 0 && nums[nums.size() - 1] != 0)
            {
                nums.push_back(nums[nums.size() - 1] * num);
            }
            else
                nums.push_back(num);

            noZero++;
        }
        else
        {
            nums.push_back(0);
            noZero = 0;
        }
    }

    int getProduct(int k)
    {
        if (k > noZero)
            return 0;
        if (k == nums.size() || k == noZero)
            return nums[nums.size() - 1];
        return nums[nums.size() - 1] / nums[nums.size() - k - 1];
    }

    void print()
    {
        for (const int &n : nums)
        {
            cout << n << " ";
        }
        cout << endl;
        cout << noZero << endl;
    }
};

int main()
{
    ProductOfNumbers *obj = new ProductOfNumbers();
    obj->add(7);
    obj->add(4);
    obj->add(5);
    /* obj->add(5);
    obj->add(4); */
    obj->print();
    cout << obj->getProduct(3);
    /* cout << obj->getProduct(3);
    cout << obj->getProduct(4);
    obj->add(8); */
    return 0;
}