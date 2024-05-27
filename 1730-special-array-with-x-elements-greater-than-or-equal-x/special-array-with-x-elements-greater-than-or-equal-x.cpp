class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int x = 1; x <= n; ++x) {
            if (nums[n - x] >= x && (n - x == 0 || nums[n - x - 1] < x)) {
                return x;
            }
        }
        return -1;
    }
};