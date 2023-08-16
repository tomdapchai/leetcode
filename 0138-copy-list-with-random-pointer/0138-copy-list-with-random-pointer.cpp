/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    int findNodeIndex(Node *head, Node *need) {//return the index i of the Node need
        if (!head || !head->next)
            return 0;
        Node *temp = head;
        int i = 0;
        while (temp != need) {
            i++;
            temp = temp->next;
        }
        return i;
    }
    Node *findNode (Node *head, int i) {//return node at index i
        Node *temp = head;
        int x = 0;
        while (x < i) {
            temp = temp->next;
            x++;
        }
        return temp;
    }
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        if (!head->next) {
            Node *result = new Node(head->val);
            if (head->random == NULL)
                result->random = NULL;
            else {
                result->random = result;
            }
            return result;
        }
        Node *temp = head;
        vector<int> List;
        vector<int> randomIndexList;
        while(temp != NULL) {
            List.push_back(temp->val);
            int randomIndex;
            if (temp->random == NULL)
                randomIndex = -1;
            else
                randomIndex = findNodeIndex(head, temp->random);
            randomIndexList.push_back(randomIndex);
            temp = temp->next;
        }
        Node *result = NULL;
        Node *current = NULL;
        delete temp;
        while (!List.empty()) {//initialize list
            Node *temp = new Node(List[0]);
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
        //random pointers
        Node *tempR = result;
        while (tempR != NULL && !randomIndexList.empty()) {
            if (randomIndexList[0] == -1)
                tempR->random = NULL;
            else
                tempR->random = findNode(result, randomIndexList[0]);
            randomIndexList.erase(randomIndexList.begin());
            tempR = tempR->next;
        }
        return result;
    }
};