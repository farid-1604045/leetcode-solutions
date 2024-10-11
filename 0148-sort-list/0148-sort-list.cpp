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
    ListNode* sortList(ListNode* head) {
        vector<int>v;
        ListNode* temp = head;
        while(temp != NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        sort(v.begin(), v.end());
        int i = 0;
        ListNode* temp1 = head;
        
        while(temp1 != NULL)
        {
            temp1->val = v[i];
            i++ ;
            temp1 = temp1->next;
        }
        
        return head;
    }
};