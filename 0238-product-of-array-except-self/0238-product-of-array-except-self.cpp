auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
        vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        int temp = 1;
        for(int i = nums.size() - 2; i >= 0; --i) {
            temp *= nums[i + 1];
            result[i] *= temp;
        }
        return result;
    }
};