class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle_length = 2 * n - 2;
        int effective_time = time % cycle_length;
        
        if (effective_time < n) {
            return effective_time + 1;
        } else {
            return 2 * n - effective_time - 1;
        }
    }
};