class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> count(n + 2, 0);

        for (int i = 0; i < n; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            count[u]++;
            count[v]++;
        }

        for (int i = 1; i <= n + 1; ++i) {
            if (count[i] == n) {
                return i;
            }
        }
        
        return -1;
    }
};