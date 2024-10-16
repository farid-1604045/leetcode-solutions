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
    ListNode *detectCycle(ListNode *head) {
        ListNode* res = NULL;
        ListNode* temp = head;
        unordered_set<ListNode*>st;
        while(temp != NULL)
        {
            if(st.find(temp) != st.end())
            {
                res = temp;
                break;
            }
            
            st.insert(temp);
            temp = temp->next;
        }
        
        return res;
    }
};