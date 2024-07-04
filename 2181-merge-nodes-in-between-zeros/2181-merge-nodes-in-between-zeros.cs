/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MergeNodes(ListNode head) {
        if (head == null) return null;
        
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        ListNode temp = head.next; // Skip the initial zero
        int sum = 0;

        while (temp != null) {
            if (temp.val == 0) {
                // We hit a zero, so create a new node with the sum and reset sum
                if (sum != 0) {
                    current.next = new ListNode(sum);
                    current = current.next;
                    sum = 0;
                }
            } else {
                // Accumulate the values between zeros
                sum += temp.val;
            }
            temp = temp.next;
        }

        return dummy.next;
    }
}