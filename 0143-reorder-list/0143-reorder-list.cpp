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
    ListNode* reverseList(ListNode* head) {//reverse
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *current = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
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
    ListNode* cloneList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *temp = head;
        vector<int> List;
        while (temp != NULL) {
            List.push_back(temp->val);
            temp = temp->next;
        }
        delete temp;
        ListNode *result = NULL;
        ListNode *current = NULL;
        while (!List.empty()) {
            ListNode *temp = new ListNode(List[0]);
            if (result == NULL) {
                result = temp;
                current = result;
            }
            else {
                current->next = temp;
                current = current->next;
            }
            List.erase(List.begin());
        }
        return result;
    }
    void reorderList(ListNode* head) {
        //create reverse list
        //then merge
        if (!head || !head->next)
            return;
        int n = lengthList(head);
        ListNode *cloneHead = cloneList(head);
        ListNode *reverseHead = reverseList(head);
        ListNode *Next = reverseHead;
        head->next = Next;
        cloneHead = cloneHead->next;
        reverseHead = reverseHead->next;
        int i = 2;
        while (i < n) {
            if (i % 2 == 0) {
                ListNode *temp = new ListNode(cloneHead->val);
                Next->next = temp;
                cloneHead = cloneHead->next;
            }
            else {
                ListNode *temp = new ListNode(reverseHead->val);
                Next->next = temp;
                reverseHead = reverseHead->next;
            }
            Next = Next->next;
            i++;
        }
        Next->next = NULL;
    }
};