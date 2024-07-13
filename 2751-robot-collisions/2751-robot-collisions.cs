public class Solution {
    public IList<int> SurvivedRobotsHealths(int[] positions, int[] healths, string directions) {
        int n = positions.Length;
        List<int> indices = new List<int>(n);
        List<int> result = new List<int>();
        Stack<int> stack = new Stack<int>();

        for (int index = 0; index < n; ++index) {
            indices.Add(index);
        }

        indices.Sort((lhs, rhs) => positions[lhs].CompareTo(positions[rhs]));

        foreach (int currentIndex in indices) {
            // Add right-moving robots to the stack
            if (directions[currentIndex] == 'R') {
                stack.Push(currentIndex);
            } else {
                while (stack.Count > 0 && healths[currentIndex] > 0) {
                    // Pop the top robot from the stack for collision check
                    int topIndex = stack.Pop();

                    // Top robot survives, current robot is destroyed
                    if (healths[topIndex] > healths[currentIndex]) {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        stack.Push(topIndex);
                    } else if (healths[topIndex] < healths[currentIndex]) {
                        // Current robot survives, top robot is destroyed
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    } else {
                        // Both robots are destroyed
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        // Collect surviving robots
        for (int index = 0; index < n; ++index) {
            if (healths[index] > 0) {
                result.Add(healths[index]);
            }
        }
        return result;
    }
}