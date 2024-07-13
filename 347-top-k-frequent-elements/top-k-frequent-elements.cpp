#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int, int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        vector<pair<int, int>> v;
        for (auto& it : m)
            v.push_back(it);
        sort(v.begin(), v.end(), cmp);
        vector<int> a;
        for (auto it = v.begin(); it != v.end(); it++)
        {
            if(k-->0)
                a.push_back(it->first);
        }
        return a;
    }
};