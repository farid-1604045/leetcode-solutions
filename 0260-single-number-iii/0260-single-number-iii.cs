public class Solution {
    public int[] SingleNumber(int[] nums) {
        int xor2no = 0;
        foreach (int num in nums) {
            xor2no ^= num;
        }

        uint lowestBit = (uint)xor2no & (uint)-(int)xor2no;

        int[] result = new int[2];
        foreach (int num in nums) {
            if ((lowestBit & num) == 0) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }

        return result;
    }
}