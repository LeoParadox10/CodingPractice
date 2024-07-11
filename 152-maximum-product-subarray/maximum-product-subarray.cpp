class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max_pro = nums[0];
        long long max_so_far = nums[0], min_so_far = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                swap(max_so_far, min_so_far);
            }
            
            max_so_far = max((long long)nums[i], max_so_far * nums[i]);
            min_so_far = min((long long)nums[i], min_so_far * nums[i]);
            if (max_so_far > LLONG_MAX / 10 || min_so_far < LLONG_MIN / 10) {
                max_so_far = nums[i];
                min_so_far = nums[i];
            }
            
            max_pro = max(max_pro, (int)max_so_far);
        }
        return max_pro;
    }
};