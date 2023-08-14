class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> ans;
        for(auto i:nums)
            ans.push_back(i);
        sort(ans.begin(), ans.end(), greater<int>());
        int x=0;
        for(int i=0;i<k;i++)
        {
            if(i==k-1)
                x=ans[i];
        }
        return x;
    }
};