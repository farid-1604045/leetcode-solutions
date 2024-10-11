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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        
        if(length == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        int removeNodeIndex = length - n;
        ListNode* temp1 = head;
        for(int i = 1; i < removeNodeIndex; i++) {
            temp1 = temp1->next;
        }
        
        ListNode* nodeToRemove = temp1->next;
        temp1->next = temp1->next->next;
        delete nodeToRemove;
        return head;
    }
};