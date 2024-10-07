class Solution {
public:
    int f(int ind, int n, vector<int> nums, vector<vector<int>> &dp, int target)
    {
        if(ind==n)
            return target==0;
        if(target+1000<0 || target+1000>=2001)
            return 0;
        if(dp[ind][target+1000]!=-1)
            return dp[ind][target+1000];
        int notTake=f(ind+1, n, nums, dp, target+nums[ind]);
        int take=f(ind+1, n, nums, dp, target-nums[ind]);
        return dp[ind][target+1000]=take+notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int> (2001, -1));
        return f(0, n, nums, dp, target);
    }
};