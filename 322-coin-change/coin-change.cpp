class Solution {
public:
    int f(int ind, vector<int> &coins, int k, vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(k%coins[ind]==0)
                return dp[ind][k]=k/coins[ind];
            return 1e9;
        }
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        int notPick=0+f(ind-1, coins, k, dp);
        int pick=INT_MAX;
        if(coins[ind]<=k)
            pick=1+f(ind, coins, k-coins[ind], dp);
        return dp[ind][k]=min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        int ways=f(n-1, coins, amount, dp);
        if(ways>=1e9)
            return -1;
        return ways;
    }
};