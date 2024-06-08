class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2)
            return false;
        unordered_map<int, int> m;
        int sum=0;
        m[0]=-1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem=k==0?sum:sum%k;
            if(m.count(rem))
            {
                if(i-m[rem]>1)
                    return true;
            }
            else
                m[rem]=i;
        }
        return false;
    }
};