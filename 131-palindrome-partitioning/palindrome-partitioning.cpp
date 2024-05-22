class Solution {
public:
    bool isPalin(string &s, int l, int r, vector<vector<int>> &dp) {
        if (dp[l][r] != -1)
            return dp[l][r];
        int start = l, end = r;
        while (l < r) {
            if (s[l] != s[r])
                return dp[start][end] = 0;
            l++, r--;
        }
        return dp[start][end] = 1;
    }

    void dfs(string &s, int ind, vector<vector<int>> &dp, vector<string> &valids, vector<vector<string>> &ans) {
        if (ind == s.size()) {
            ans.push_back(valids);
            return;
        }
        for (int i = ind; i < s.size(); ++i) {
            if (isPalin(s, ind, i, dp)) {
                valids.push_back(s.substr(ind, i - ind + 1));
                dfs(s, i + 1, dp, valids, ans);
                valids.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<string> valids;
        vector<vector<string>> ans;
        dfs(s, 0, dp, valids, ans);
        return ans;
    }
};