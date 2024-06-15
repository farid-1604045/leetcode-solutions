class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruit = 0;
        int start = 0;
        unordered_map<int, int> basket;
    
        for (int end = 0; end < fruits.size(); end++) {
            basket[fruits[end]]++;
    
            while (basket.size() > 2) {
                basket[fruits[start]]--;
                if (basket[fruits[start]] == 0) {
                    basket.erase(fruits[start]);
                }
                start++;
            }
    
            maxFruit = max(maxFruit, end - start + 1);
        }
    
        return maxFruit;
    }
};