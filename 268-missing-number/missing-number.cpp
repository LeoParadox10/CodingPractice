class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> ans(nums.size()+1, false);
        for(int i=0;i<nums.size();i++)
            ans[nums[i]]=true;
        int pos=0;
        for(int i=0;i<ans.size();i++)
        {
            if(!ans[i])
            {
                pos=i;
                break;
            }
        }
        return pos;
    }
};