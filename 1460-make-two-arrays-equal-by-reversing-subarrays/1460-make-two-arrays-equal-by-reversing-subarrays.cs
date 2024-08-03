public class Solution {
    public bool CanBeEqual(int[] target, int[] arr) {
        Array.Sort(arr);
        Array.Sort(target);

        // Compare the arrays
        if (arr.SequenceEqual(target))
        {
            return true;
        }

        return false;
    }
}