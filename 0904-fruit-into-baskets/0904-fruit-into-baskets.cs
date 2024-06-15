public class Solution {
    public int TotalFruit(int[] fruits) {
        int maxFruit = 0;
        int start = 0;
        Dictionary<int, int> basket = new Dictionary<int, int>();

        for (int end = 0; end < fruits.Length; end++) {
            if (basket.ContainsKey(fruits[end])) {
                basket[fruits[end]]++;
            } else {
                basket[fruits[end]] = 1;
            }

            while (basket.Count > 2) {
                basket[fruits[start]]--;
                if (basket[fruits[start]] == 0) {
                    basket.Remove(fruits[start]);
                }
                start++;
            }

            maxFruit = Math.Max(maxFruit, end - start + 1);
        }

        return maxFruit;
    }
}