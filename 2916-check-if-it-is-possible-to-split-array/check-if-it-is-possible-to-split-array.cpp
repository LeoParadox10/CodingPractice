class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]+nums[i]>=m)
                return true;
        }
        return nums.size()<=2;
    }
};