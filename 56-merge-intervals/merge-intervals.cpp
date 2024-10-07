class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<int> ini=intervals[0];
        vector<vector<int>> ans;
        for(int i=1;i<n;i++)
        {
            vector<int> t={intervals[i][0], intervals[i][1]};
            if(t[0]<=ini[1])
            {
                ini[1]=max(t[1], ini[1]);
            }
            else
            {
                ans.push_back(ini);
                ini=t;
            }
        }
        ans.push_back(ini);
        return ans;
    }
};