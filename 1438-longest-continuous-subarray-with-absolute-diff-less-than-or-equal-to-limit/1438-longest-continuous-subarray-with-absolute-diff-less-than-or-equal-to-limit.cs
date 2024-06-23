public class Solution {
    public int LongestSubarray(int[] nums, int limit) {
        Deque<int> maxDeque = new Deque<int>();
        Deque<int> minDeque = new Deque<int>();
        int left = 0, right;
        int maxLength = 0;

        for (right = 0; right < nums.Length; ++right) {
            // Maintain the decreasing deque for the max value in the current window
            while (maxDeque.Count > 0 && nums[maxDeque.Back] <= nums[right])
                maxDeque.PopBack();
            maxDeque.PushBack(right);

            // Maintain the increasing deque for the min value in the current window
            while (minDeque.Count > 0 && nums[minDeque.Back] >= nums[right])
                minDeque.PopBack();
            minDeque.PushBack(right);

            // If the window is invalid, move the left pointer to the right
            while (nums[maxDeque.Front] - nums[minDeque.Front] > limit) {
                ++left;
                if (maxDeque.Front < left) maxDeque.PopFront();
                if (minDeque.Front < left) minDeque.PopFront();
            }

            // Update the maxLength
            maxLength = Math.Max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}

public class Deque<T> {
    private LinkedList<T> list = new LinkedList<T>();

    public void PushBack(T value) {
        list.AddLast(value);
    }

    public void PopBack() {
        if (list.Count > 0)
            list.RemoveLast();
    }

    public T Back {
        get { return list.Last.Value; }
    }

    public void PushFront(T value) {
        list.AddFirst(value);
    }

    public void PopFront() {
        if (list.Count > 0)
            list.RemoveFirst();
    }

    public T Front {
        get { return list.First.Value; }
    }

    public int Count {
        get { return list.Count; }
    }
}