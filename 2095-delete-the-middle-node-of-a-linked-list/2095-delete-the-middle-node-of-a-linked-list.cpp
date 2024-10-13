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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr)
        {
            return nullptr;
        }
        
        ListNode* temp = head;
        int cnt = 1;
        while(temp->next != nullptr)
        {
            cnt++;
            temp = temp->next;
        }
        
        int removable_Node = cnt/2;
        ListNode* temp1 = head;
        int newCnt = 1;
        while(temp1 != nullptr)
        {
            if(newCnt == removable_Node)
            {
                ListNode* newNode = new ListNode();
                newNode = temp1->next;
                temp1->next = temp1->next->next;
                delete newNode;
            }
            
            newCnt++;
            temp1 = temp1->next;
        }
        
        return head;
    }
};