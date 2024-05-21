class Solution {
public:

    void f(vector<vector<int>> &ans, int ind, vector<int> curr, vector<int> nums)
    {
        if(ind==-1)
        {
            ans.push_back(curr);
            return;
        }
        f(ans, ind-1, curr, nums);
        curr.push_back(nums[ind]);
        f(ans, ind-1, curr, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        f(ans, n-1, curr, nums);
        return ans;
    }
};