class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> indegree(n, 0);
        for(auto it:roads)
        {
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        sort(indegree.begin(), indegree.end());
        long long ans=0;
        for(int i=0;i<n;i++)
            ans+=(i+1)*indegree[i];
        return ans;
    }
};