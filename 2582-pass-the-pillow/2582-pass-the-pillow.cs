public class Solution {
    public int PassThePillow(int n, int time) {
        int position = 1; // Starting position
        bool forward = true; // Initial direction is forward

        for (int t = 1; t <= time; ++t) {
            if (forward) {
                // Move forward
                if (position == n) {
                    // Change direction to backward if at the last person
                    forward = false;
                    position--;
                } else {
                    position++;
                }
            } else {
                // Move backward
                if (position == 1) {
                    // Change direction to forward if at the first person
                    forward = true;
                    position++;
                } else {
                    position--;
                }
            }
        }

        return position;
    }
}