class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> ans(n);
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<n;i++)
            pq.push({score[i], i});
        int c=1;
        while(!pq.empty())
        {
            int org=pq.top().second;
            pq.pop();
            if(c==1)
                ans[org]="Gold Medal";
            else if(c==2)
                ans[org]="Silver Medal";
            else if(c==3)
                ans[org]="Bronze Medal";
            else
                ans[org]=to_string(c);
            c++;
        }
        return ans;
    }
};