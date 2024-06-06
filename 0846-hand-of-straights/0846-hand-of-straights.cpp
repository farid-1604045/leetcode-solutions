class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        sort(hand.begin(), hand.end());

        map<int, int> cardCount;
        for (int card : hand) {
            cardCount[card]++;
        }

        for (int card : hand) {
            if (cardCount[card] == 0) continue;

            for (int i = 0; i < groupSize; i++) {
                int currentCard = card + i;
                if (cardCount[currentCard] == 0) {
                    return false;
                }
                cardCount[currentCard]--;
            }
        }

        return true;
    }
};