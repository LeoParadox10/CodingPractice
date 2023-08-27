class Solution {
public:
    bool f(int i, int k, vector<int> &s, int n, vector<vector<int>> &dp)
    {
        if(i==n-1)
            return true;
        bool a=false;
        if(dp[i][k]!=-1)
            return  dp[i][k];
        for(int j=i+1;j<n;j++)
        {
            if(s[j]>(s[i]+k+1))
                break;
            else if(s[j]==(s[i]+k-1))
                a|=f(j, k-1, s, n, dp);
            else if(s[j]==(s[i]+k))
                a|=f(j, k, s, n, dp);
            else if(s[j]==(s[i]+k+1))
                a|=f(j, k+1, s, n, dp);
        }
        return dp[i][k]=a;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>> dp(n+2, vector<int>(2000, -1));
        return f(0, 0, stones, n, dp);
    }
};