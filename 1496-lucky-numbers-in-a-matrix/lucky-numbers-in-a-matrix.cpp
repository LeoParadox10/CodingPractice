class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            int tmp=INT_MAX;
            for(int j=0;j<m;j++)
            {
                tmp=min(tmp, matrix[i][j]);
            }
            mp[tmp]++;
        }
        for(int i=0;i<m;i++)
        {
            int tmp=INT_MIN;
            for(int j=0;j<n;j++)
            {
                tmp=max(tmp, matrix[j][i]);
            }
            mp[tmp]++;
        }
        vector<int> lucky;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==2)
            {
                lucky.push_back(it->first);
            }
        }
        return lucky;
    }
};