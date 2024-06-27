class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> nodeCount;
        for (const auto& edge : edges) {
            nodeCount[edge[0]]++;
            nodeCount[edge[1]]++;
        }

        for (const auto& [node, count] : nodeCount) {
            if (count == edges.size()) {
                return node;
            }
        }
        return -1;
    }
};