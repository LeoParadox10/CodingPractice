class Solution {
public:
    int f(vector<int> &nums, int goal)
    {
        int i=0, j=0, n=nums.size(), cnt=0, ans=0;
        while(j<n)
        {
            if(nums[j]%2)
                cnt++;
            while(i<=j && cnt>goal)
            {
                if(nums[i]%2)
                    cnt--;
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k)-f(nums, k-1);
    }
};