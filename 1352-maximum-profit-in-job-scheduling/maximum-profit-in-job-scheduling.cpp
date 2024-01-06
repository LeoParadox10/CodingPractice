class Solution {
public:
    int dp[50001];

    int solve(vector<vector<int>> &jobs, vector<int> &start, int n, int id)
    {
        if(id==n)
            return 0;
        if(dp[id]!=-1)
            return dp[id];
        int nextIndex=lower_bound(start.begin(), start.end(), jobs[id][1]) - start.begin();
        int maxProfit=max(solve(jobs, start, n, id+1), jobs[id][2]+solve(jobs, start, n, nextIndex));
        return dp[id]=maxProfit;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>> jobs;
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<n;i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        for(int i=0;i<n;i++)
            startTime[i]=jobs[i][0];
        return solve(jobs, startTime, n, 0);
    }
};