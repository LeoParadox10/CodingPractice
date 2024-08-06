class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> s;
        for(auto it:nums2)
        {
            while(!s.empty() && s.top()<it)
            {
                mp[s.top()]=it;
                s.pop();
            }
            s.push(it);
        }
        vector<int> ans;
        for(auto it:nums1)
        {
            if(mp.find(it)!=mp.end())
                ans.push_back(mp[it]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};