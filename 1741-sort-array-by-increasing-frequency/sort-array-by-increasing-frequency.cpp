class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &it:nums)
            mp[it]++;
        map<int, vector<int>> freq;
        for(auto &it:mp)
            freq[it.second].push_back(it.first);
        vector<int> ans;
        for(auto &it:freq)
        {
            if(it.second.size()>1)
                sort(it.second.rbegin(), it.second.rend());
            for(auto &x:it.second)
            {
                for(int i=0;i<it.first;i++)
                    ans.push_back(x);
            }
        }
        return ans;
    }
};