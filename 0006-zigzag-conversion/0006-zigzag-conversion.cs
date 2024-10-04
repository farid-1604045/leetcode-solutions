public class Solution {
    public string Convert(string s, int numRows) {
        if (numRows == 1) return s;  // Special case, no zigzag required

        // Create a list of strings for each row
        List<string> rows = new List<string>(new string[Math.Min(numRows, s.Length)]);

        int curRow = 0;   
        bool goingDown = false;

        // Traverse each character in the input string
        foreach (char c in s) {
            rows[curRow] += c;  // Add the character to the current row
            
            // If we're at the top or bottom, reverse direction
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;

            // Update the current row (move up or down)
            curRow += goingDown ? 1 : -1;
        }

        // Concatenate all the rows to form the final result
        string result = "";
        foreach (string row in rows) {
            result += row;
        }

        return result;
    }
}
