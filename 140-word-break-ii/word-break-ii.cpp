class Solution {
public:
    vector<string> f(string &s, vector<string> &dict, int ind, vector<vector<string>> &dp) {
        if (ind == 0) {
            return {""};
        }
        if (!dp[ind].empty()) {
            return dp[ind];
        }
        vector<string> ans;
        for (string w : dict) {
            int m = w.size();
            if (ind >= m && s.substr(ind - m, m) == w) {
                vector<string> t = f(s, dict, ind - m, dp);
                for (string r : t) {
                    ans.push_back((r.empty() ? "" : r + " ") + w);
                }
            }
        }
        return dp[ind] = ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<string>> dp(n + 1);
        return f(s, wordDict, n, dp);
    }
};
