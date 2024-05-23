class Solution {
public:
    int f(vector<int> &arr, int ind, int k, vector<int> &dp) {
        if(ind == -1)
            return 1;
        
        int pick = 0;
        int notPick=0;
        if(find(dp.begin(), dp.end(), arr[ind] - k) == dp.end() && 
            find(dp.begin(), dp.end(), arr[ind] + k) == dp.end()) {
            dp.push_back(arr[ind]);
            pick = f(arr, ind-1, k, dp);
            dp.pop_back();
        }
        notPick = f(arr, ind-1, k, dp);
        return pick + notPick;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> dp;
        int n = nums.size();
        return f(nums, n-1, k, dp)-1;
    }
};
