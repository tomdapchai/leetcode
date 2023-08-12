auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    static bool pairCompare(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> numMap;
        for(int &i : nums) {
            numMap[i].push_back(i);
        }
        unordered_map<int, int> freqMap;
        for(int &i : nums) {
            freqMap[i] = numMap[i].size();
        }
        vector<pair<int, int>> temp(freqMap.begin(), freqMap.end());
        sort(temp.begin(), temp.end(), pairCompare);
        for(int i = 0; i < k; ++i) {
            result.push_back(temp[i].first);
        }
        return result;
    }
};