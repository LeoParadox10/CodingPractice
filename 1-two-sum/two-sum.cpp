class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans(2);
        int i=0, j=1;
        while(i<n-1 && j<n)
        {
            if(target-nums[i]==nums[j])
            {
                ans[0]=i;
                ans[1]=j;
                break;
            }
            if(j==n-1)
            {
                i=i+1;
                j=i+1;
            }
            else
                j=j+1;
        }
        return ans;
    }
};