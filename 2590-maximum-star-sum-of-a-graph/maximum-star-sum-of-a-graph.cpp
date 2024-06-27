class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        if (edges.size() == 0) {
            int ans = INT_MIN;  // Corrected to INT_MIN
            for (int i = 0; i < n; i++) {
                ans = max(ans, vals[i]);
            }
            return ans;
        }
        
        vector<vector<int>> adjL(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjL[u].push_back(vals[v]);
            adjL[v].push_back(vals[u]);
        }
        
        long long ans = LLONG_MIN;  // Initialize ans to a very small value
        for (int i = 0; i < n; i++) {
            long long temp = 0;
            sort(adjL[i].rbegin(), adjL[i].rend());
            for (int j = 0; j < min(k, (int)adjL[i].size()); j++) {  // Ensure we do not access out of bounds
                if (adjL[i][j] > 0)
                    temp += adjL[i][j];
            }
            temp += vals[i];
            ans = max(ans, temp);
        }
        
        return ans;
    }
};
