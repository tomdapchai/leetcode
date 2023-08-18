/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    int listSize(ListNode *head) {
        if (!head)
            return 0;
        int result = 0;
        ListNode *temp = head;
        while (temp != NULL) {
            result ++;
            temp = temp->next;
        }
        return result;
    }
    vector<int> reverseGroup(vector<int> nums) {
        vector<int> result;
        while (!nums.empty()) {
            result.push_back(nums.back());
            nums.pop_back();
        }
        return result;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int loop = listSize(head) / k;
        vector<int> nums;
        ListNode *temp = head;
        while (temp != NULL) {
            nums.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> reverseNum;
        for (int i = 0; i < loop; i++) {
            vector<int> temp;
            for (int j = 0; j < k; j++) {
                temp.push_back(nums[0]);
                nums.erase(nums.begin());
            }
            vector<int> reverseTemp = reverseGroup(temp);
            for (int &k : reverseTemp)
                reverseNum.push_back(k);
        }
        for (int &i : nums)
            reverseNum.push_back(i);
        ListNode *result = NULL;
        ListNode *current = NULL;
        while (!reverseNum.empty()) {
            ListNode *temp = new ListNode(reverseNum[0]);
            if (result == NULL) {
                result = temp;
                current = result;
            }
            else {
                current->next = temp;
                current = current->next;
            }
            reverseNum.erase(reverseNum.begin());
        }
        return result;
    }
};