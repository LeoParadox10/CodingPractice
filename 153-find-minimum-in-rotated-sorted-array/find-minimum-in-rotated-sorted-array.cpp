class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int s=0;
        int e=n-1;
        while(s<=e)
        {
            int mid=s-(s-e)/2;
            if(nums[s]<=nums[mid])
            {
                mini=min(mini, nums[s]);
                s=mid+1;
            }
            else
            {
                mini=min(mini, nums[mid]);
                e=mid-1;   
            }
        }
        return mini;
    }
};