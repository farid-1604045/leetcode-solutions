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
    public int[] NodesBetweenCriticalPoints(ListNode head) {
        List<int> criticalPoints = new List<int>();
        int position = 1; // Start from 1 for the first node
        ListNode prev = head;
        ListNode curr = head.next;

        // Traverse the list and identify critical points
        while (curr != null && curr.next != null) {
            ListNode next = curr.next;
            if ((curr.val > prev.val && curr.val > next.val) || 
                (curr.val < prev.val && curr.val < next.val)) {
                criticalPoints.Add(position);
            }
            prev = curr;
            curr = next;
            position++;
        }

        // If there are fewer than two critical points, return [-1, -1]
        if (criticalPoints.Count < 2) {
            return new int[] { -1, -1 };
        }

        int minDistance = int.MaxValue;
        int maxDistance = criticalPoints[criticalPoints.Count - 1] - criticalPoints[0];

        // Calculate the minimum distance between consecutive critical points
        for (int i = 1; i < criticalPoints.Count; i++) {
            minDistance = Math.Min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }

        return new int[] { minDistance, maxDistance };
    }
}