#include<bits/stdc++.h>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* countTemp = head;
        while(countTemp != NULL)
        {
            n++;
            countTemp = countTemp->next;
        }

        int divisibleCount = n;
        ListNode* newHead = head;
        
        while(divisibleCount >= k)
        {
            vector<int>v;
            ListNode* temp = newHead;
            for(int i=0; i<k; i++)
            {
                v.push_back(temp->val);
                temp = temp->next;
            }

            reverse(v.begin(), v.end());

            ListNode* newTemp = newHead;
            for(int i=0; i<k; i++)
            {
                newTemp->val = v[i];
                newTemp = newTemp->next;
            }

            newHead = newTemp;

            divisibleCount -= k;
        }
        
        return head;
    }
};