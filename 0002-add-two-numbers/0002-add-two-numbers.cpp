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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> list1;
        vector<int> list2;
        vector<int> sub;
        ListNode *result = NULL;
        ListNode *current = NULL;
        stack<int> big;
        while (l1 != NULL) {
            list1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            list2.push_back(l2->val);
            l2 = l2->next;
        }
        if (list1.size() != list2.size()) {
            int n = list1.size() > list2.size() ? list1.size() - list2.size() : list2.size() - list1.size();
            if (list1.size() > list2.size()) {
                while (list1.size() > list2.size()) {
                    big.push(list1.back());
                    list1.pop_back();
                }
            }
            else {
                while (list2.size() > list1.size()) {
                    big.push(list2.back());
                    list2.pop_back();
                }
            }
        }
        int carry = 0;
        while (!list1.empty() || !list2.empty()) {
            int temp = 0;
            if (list1[0] + list2[0] + carry < 10) {
                temp = list1[0] + list2[0] + carry;
                carry = 0;
            }
            else {
                temp = (list1[0] + list2[0] + carry) % 10;
                carry = 1;
            }
            list1.erase(list1.begin());
            list2.erase(list2.begin());
            sub.push_back(temp);
        }
        while (!big.empty()) {
            int temp;
            if (big.top() + carry < 10) {
                temp = big.top() + carry;
                carry = 0;
            }
            else {
                temp = (big.top() + carry) % 10;
                carry = 1;
            }
            sub.push_back(temp);
            big.pop();
        }
        if (big.empty() && carry == 1)
            sub.push_back(1);
        while (!sub.empty()) {
            ListNode *temp = new ListNode(sub[0]);
            if (result == NULL) {
                result = temp;
                current = result;
            }
            else {
                current->next = temp;
                current = current->next;
            }
            sub.erase(sub.begin());
        }
        return result;
    }
};