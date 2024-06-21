class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        
        // Calculate initial satisfied customers
        int initialSatisfied = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                initialSatisfied += customers[i];
            }
        }
        
        // Calculate the number of additional satisfied customers by applying the technique
        int maxIncrease = 0;
        int currentIncrease = 0;
        
        // Initial window calculation
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                currentIncrease += customers[i];
            }
        }
        
        maxIncrease = currentIncrease;
        
        // Sliding window
        for (int i = minutes; i < n; i++) {
            if (grumpy[i] == 1) {
                currentIncrease += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                currentIncrease -= customers[i - minutes];
            }
            maxIncrease = max(maxIncrease, currentIncrease);
        }
        
        return initialSatisfied + maxIncrease;
    }
};