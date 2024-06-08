public class Solution {
    public int CountStudents(int[] arr, int pages)
    {
        int n = arr.Length; // Size of the array
        int students = 1;
        long pagesStudent = 0;

        for (int i = 0; i < n; i++)
        {
            if (pagesStudent + arr[i] <= pages)
            {
                // Add pages to the current student
                pagesStudent += arr[i];
            }
            else
            {
                // Add pages to the next student
                students++;
                pagesStudent = arr[i];
            }
        }

        return students;
    }
    public int SplitArray(int[] nums, int k) {
        int n = nums.Length;
        if (k > n) return -1;

        int low = nums.Max();
        int high = nums.Sum();

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int students = CountStudents(nums, mid);

            if (students > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low;
    }
}