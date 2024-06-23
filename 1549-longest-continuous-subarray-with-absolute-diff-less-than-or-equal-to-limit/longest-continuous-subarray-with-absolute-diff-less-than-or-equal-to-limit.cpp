class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int len = 0, left = 0, right = 0, n = nums.size();
        multiset<int> s;
        while (right < n)
        {
            s.insert(nums[right]);
            while (*s.rbegin() - *s.begin() > limit)
            {
                multiset<int>::iterator ptr = s.find(nums[left++]);
                s.erase(ptr);
            }
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};