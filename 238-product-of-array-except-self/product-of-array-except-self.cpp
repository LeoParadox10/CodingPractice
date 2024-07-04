class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int pro=1;
        unordered_map<int, int> m;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
                pro*=nums[i];
            else
                m[nums[i]]++;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                if(m[0]>0)
                    ans[i]=0;
                else
                    ans[i]=pro/nums[i];
            }
            else
            {
                if(m[0]>1)
                    ans[i]=0;
                else
                    ans[i]=pro;
            }
        }
        return ans;
    }
};