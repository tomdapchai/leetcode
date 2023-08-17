/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    bool hasCycle(ListNode *head) {
        while (head != NULL) {
            if (head->next <= head && head->next != NULL)
                return true;
            head = head->next;
        }
        return false;
    }
};