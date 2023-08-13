class Solution {
public:
    bool isValid(vector<char> vec) {
        unordered_map<char, vector<char>> freqMap;
        for(char &i : vec) {
            if (i < '1' || i > '9')
                continue;
            freqMap[i].push_back(i);
        }
        for(auto &i : freqMap) {
            if (i.second.size() > 1)
                return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(auto &i : board) {//row check
            if (!isValid(i))
                return false;
        }
        for (int i = 0; i < 9; i++) {// col check
            vector<char> temp;
            for (int j = 0; j < 9; j++)
                temp.push_back(board[j][i]);
            if (!isValid(temp))
                return false;
        }
        int i = 0, j = 0;
        while (j < 9) {//block check
            int currentJ = j;
            for (int x = 0; x < 3; x++) {//loop over 3 row
                vector<char> temp;
                for (int k = 0; k < 3; k++) {//loop over row
                    int currentI = i;
                    for(int h = 0; h < 3; h++) {
                        temp.push_back(board[j][i]);
                        i++;
                    }
                    j++;
                    i = currentI; // reset each row
                }
                if (!isValid(temp))
                    return false;
                i += 3;
                if (i >= 8)
                    i = 0;
                j = currentJ; // reset each block
            }
            j += 3;
        }
        return true;
    }
};