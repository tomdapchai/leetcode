auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> strMap;
        for (string &i : strs) {
            string temp = i;
            sort(temp.begin(), temp.end());
            strMap[temp].push_back(i);
        }
        for (auto &i : strMap) {
            result.push_back(i.second);
        }
        return result;
    }
};