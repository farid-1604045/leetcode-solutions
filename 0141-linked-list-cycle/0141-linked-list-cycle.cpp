/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>st;
        ListNode* temp = head;
        bool ok = false;
        while(temp != NULL)
        {
            if(st.find(temp) != st.end())
            {
                ok = true;
                break;
            }
            st.insert(temp);
            temp = temp->next;
        }
        
        return ok;
    }
};