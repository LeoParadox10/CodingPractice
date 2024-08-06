class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));
        for(int k=0;k<=amount;k++)
        {   
            if(k%coins[0]==0)
                dp[0][k]=k/coins[0];
            else
                dp[0][k]=1e9;
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int k=0;k<=amount;k++)
            {
                int notPick=0+dp[ind-1][k];
                int pick=INT_MAX;
                if(coins[ind]<=k)
                    pick=1+dp[ind][k-coins[ind]];
                dp[ind][k]=min(pick, notPick);
            }
        }
        int ways=dp[n-1][amount];
        if(ways==1e9)
            return -1;
        return ways;
    }
};