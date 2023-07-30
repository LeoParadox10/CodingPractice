class Solution {
public:
    bool subsetSum(vector<int> &nums, int n, int sum)
    {
        vector<bool> prev(sum+1, false);
        prev[0]=false;
        if(nums[0]<=sum)
            prev[nums[0]]=true;
        
        for(int i=1;i<n;i++)
        {
            vector<bool> curr(sum+1, false);
            for(int target=1;target<=sum;target++)
            {
                bool notTake=prev[target];
                bool take=false;
                if(nums[i]<=target)
                    take=prev[target-nums[i]];
                curr[target]=take || notTake;
            }
            prev=curr;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=accumulate(begin(nums), end(nums), 0);
        if(totalSum%2!=0)
            return false;
        return subsetSum(nums, n, totalSum/2);
    }
};