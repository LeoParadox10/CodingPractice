class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        for(auto it:nums)
            mp[it]++;
        int x=n/3;
        vector<int> ans;
        unordered_map<int, bool> m1;
        for(auto it:nums)
        {
            if(mp[it]>x && m1.find(it)==m1.end())
            {
                ans.push_back(it);
                m1[it]=true;
            }
        }
        return ans;
    }
};