class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map <int, vector<int>> numMap;
        int result;
        for (int &i : nums)
            numMap[i].push_back(i);
        for (auto &i : numMap) {
            if (i.second.size() > 1) {
                result = i.first;
                break;
            }  
        }
        return result;
    }
};