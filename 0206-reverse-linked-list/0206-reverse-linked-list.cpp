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
private: 
    ListNode* reverse(ListNode* temp)
    {
        if(temp == NULL || temp->next == nullptr)
        {
            return temp;
        }

        ListNode* newHead = reverse(temp->next);
        ListNode* front = temp->next;
        front->next = temp;
        temp->next = nullptr;
        return newHead;
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        
        return reverse(head);
    }
};