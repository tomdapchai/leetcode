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
    int lengthList(ListNode *head) {
        ListNode *temp = head;
        int c = 0;
        while(temp != NULL) {
            c++;
            temp = temp->next;
        }
        delete temp;
        return c;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return head;
        if (!head->next) {
            head = NULL;
            return head;
        }

        if (n == lengthList(head)) {
            head = head->next;
        }
        else {
            ListNode *temp = head;
            int pos = lengthList(head) - n;
            int i = 0;
            while (i < pos - 1) {
                temp = temp->next;
                i++;
            }
            temp->next = temp->next->next;
        }
        return head;
    }
};