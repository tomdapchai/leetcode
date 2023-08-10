auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        vector<char> char1(s.begin(), s.end());
        vector<char> char2(t.begin(), t.end());
        sort(char1.begin(), char1.end());
        sort(char2.begin(), char2.end());
        if (char1 == char2)
            return true;
        return false;
    }
};