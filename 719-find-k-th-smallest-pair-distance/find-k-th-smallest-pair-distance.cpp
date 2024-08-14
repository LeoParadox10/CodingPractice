class Solution {
public:
    bool isValid(int dist, vector<int> &nums, int k)
    {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int j=upper_bound(nums.begin() + i + 1, nums.end(), nums[i] + dist) - nums.begin();
            cnt+=j-i-1;
        }
        return cnt>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l=0;
        int h=1e6;
        int ans=INT_MAX;
        int n=nums.size();
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(isValid(mid, nums, k))
            {
                ans=min(ans, mid);
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};