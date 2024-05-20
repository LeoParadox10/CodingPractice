class Solution {
public:
    int f(vector<int> &nums, int ind, int sum)
    {
        if(ind==-1)
            return sum;
        int x=nums[ind];
        int notTake=f(nums, ind-1, sum^x);
        int take=f(nums, ind-1, sum);
        return take+notTake;
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        return f(nums, n-1, 0);
    }
};