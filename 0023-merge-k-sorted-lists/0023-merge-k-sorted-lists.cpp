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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nums;
        ListNode *result = NULL;
        ListNode *current = NULL;
        for (auto &i : lists) {
            while (i != NULL) {
                nums.push_back(i->val);
                i = i->next;
            }
        }
        sort(nums.begin(), nums.end());
        while (!nums.empty()) {
            ListNode *temp = new ListNode(nums[0]);
            if (result == NULL) {
                result = temp;
                current = result;
            }
            else {
                current->next = temp;
                current = current->next;
            }
            nums.erase(nums.begin());
        }
        return result;
    }
};