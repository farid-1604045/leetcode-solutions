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
    ListNode* mergeNodes(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        ListNode* temp = head->next; // Skip the initial zero
        int sum = 0;

        while (temp) {
            if (temp->val == 0) {
                // We hit a zero, so create a new node with the sum and reset sum
                if (sum != 0) {
                    current->next = new ListNode(sum);
                    current = current->next;
                    sum = 0;
                }
            } else {
                // Accumulate the values between zeros
                sum += temp->val;
            }
            temp = temp->next;
        }

        ListNode* result = dummy->next;
        delete dummy; // Clean up the dummy node
        return result;
    }
};