class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=INT_MIN;
        int max_curr=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>nums[i]+max_curr)
                max_curr=nums[i];
            else
                max_curr+=nums[i];
            max_sum=max(max_sum, max_curr);
        }
        return max_sum;
    }
};