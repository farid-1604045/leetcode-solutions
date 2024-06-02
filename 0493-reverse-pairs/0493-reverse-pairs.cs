public class Solution {
    void Merge(List<int> arr, int low, int mid, int high) {
        List<int> temp = new List<int>(); // temporary list
        int left = low;  // starting index of left half of arr
        int right = mid + 1; // starting index of right half of arr

        // storing elements in the temporary array in a sorted manner
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.Add(arr[left]);
                left++;
            } else {
                temp.Add(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left
        while (left <= mid) {
            temp.Add(arr[left]);
            left++;
        }

        // if elements on the right half are still left
        while (right <= high) {
            temp.Add(arr[right]);
            right++;
        }

        // transferring all elements from temporary to arr
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int CountPairs(List<int> arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2L * arr[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int MergeSort(List<int> arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2;
        cnt += MergeSort(arr, low, mid);  // left half
        cnt += MergeSort(arr, mid + 1, high); // right half
        cnt += CountPairs(arr, low, mid, high); // Modification
        Merge(arr, low, mid, high);  // merging sorted halves
        return cnt;
    }
    public int ReversePairs(int[] nums) {
        List<int> arr = new List<int>(nums);
        int n = arr.Count;
        return MergeSort(arr, 0, n - 1);
    }
}