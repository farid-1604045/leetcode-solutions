class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flips = 0;
        deque<int> flipQueue;

        for (int i = 0; i < nums.size(); ++i) {
            if (!flipQueue.empty() && flipQueue.front() == i) {
                flipQueue.pop_front();
            }

            if (flipQueue.size() % 2 == nums[i]) {
                if (i + k > nums.size()) {
                    return -1;
                }
                flips++;
                flipQueue.push_back(i + k);
            }
        }

        return flips;
    }
};