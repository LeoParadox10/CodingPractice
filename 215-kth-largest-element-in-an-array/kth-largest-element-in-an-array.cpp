class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int x=0;
        for(int i=0;i<k;i++)
        {
            if(i==k-1)
                x=nums[i];
        }
        return x;
    }
};