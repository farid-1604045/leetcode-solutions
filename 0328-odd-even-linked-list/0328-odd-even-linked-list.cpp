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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
        {
            return nullptr;
        }
        vector<int>v;
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL)
        {
            v.push_back(temp->val);
            temp = temp->next->next;
        }

        if(temp != NULL)
        {
            v.push_back(temp->val);
        }

        ListNode* temp1 = head->next;
        while(temp1 != NULL && temp1->next != NULL)
        {
            v.push_back(temp1->val);
            temp1 = temp1->next->next;
        }

        if(temp1 != NULL)
        {
            v.push_back(temp1->val);
        }

        ListNode* temp2 = head;
        int i = 0;

        while(temp2 != NULL)
        {
            temp2->val = v[i];
            temp2 = temp2->next;
            i++;
        }

        return head;
    }
};