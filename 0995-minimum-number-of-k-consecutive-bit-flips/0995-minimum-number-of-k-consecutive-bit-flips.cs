public class Solution {
    public int MinKBitFlips(int[] nums, int k) {
        int flips = 0;
        Queue<int> flipQueue = new Queue<int>();

        for (int i = 0; i < nums.Length; ++i) {
            // Remove flips that are out of the current window
            if (flipQueue.Count > 0 && flipQueue.Peek() == i) {
                flipQueue.Dequeue();
            }

            // Check if we need to flip at position i
            if (flipQueue.Count % 2 == nums[i]) {  // If parity of flips affecting nums[i] matches its value
                // If flipping at i would go out of bounds, return -1
                if (i + k > nums.Length) {
                    return -1;
                }
                // Perform a flip and record its end position
                flips++;
                flipQueue.Enqueue(i + k);
            }
        }

        return flips;
    }
}