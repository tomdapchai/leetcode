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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        vector<int> temp;
        ListNode * temp1 = list1;
        ListNode * temp2 = list2;
        while(temp1 != NULL) {
            temp.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while(temp2 != NULL) {
            temp.push_back(temp2->val);
            temp2 = temp2->next;
        }
        sort(temp.begin(), temp.end());
        ListNode* result = nullptr;
    ListNode* current = nullptr;
    
    while (!temp.empty()) {
        ListNode* newNode = new ListNode(temp[0]);
        
        if (result == nullptr) {
            result = newNode;
            current = result;
        } else {
            current->next = newNode;
            current = current->next;
        }
        
        temp.erase(temp.begin());
    }
        return result;
    }
};