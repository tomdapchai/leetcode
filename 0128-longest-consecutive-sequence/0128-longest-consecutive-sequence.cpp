auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                while ((i < nums.size() - 1) && (nums[i] == nums[i + 1])) {
                    nums.erase(nums.begin() + i);
                }
            }
        }
        int maxSequence = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + 1 == nums[i + 1]) {
                int seqCount = 1;
                while ((i < nums.size() - 1) && (nums[i] + 1 == nums[i + 1])) {
                    seqCount++;
                    i++;
                }
                if (seqCount > maxSequence)
                    maxSequence = seqCount;
            }
        }
        return maxSequence;
    }
};