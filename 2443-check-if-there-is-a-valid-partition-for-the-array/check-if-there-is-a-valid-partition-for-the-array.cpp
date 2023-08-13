class Solution {
public:
  bool solve(vector<int> &a, vector<int> &dp, int i, int n)
  {
    if(i>=n)
      return true;

    if(dp[i]!=-1)
      return dp[i];
    if(i+1<n && a[i]==a[i+1])
    {
      dp[i]=solve(a, dp, i+2, n);
      if(dp[i])
        return true;
      if(i+2<n && a[i]==a[i+2])
      {
        dp[i]=solve(a, dp, i+3, n);
        if(dp[i])
          return true;
      }
    }
    if(i+2<n && a[i+1]-a[i]==1 && a[i+2]-a[i]==2)
    {
      dp[i]=solve(a, dp, i+3, n);
      if(dp[i])
        return true;
    }
    return dp[i]=false;
  }
  bool validPartition(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n, -1);
    return solve(nums, dp, 0, n);
  }
};
