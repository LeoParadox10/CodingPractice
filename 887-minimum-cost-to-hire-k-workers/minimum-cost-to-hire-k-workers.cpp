class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> workers;
        for(int i=0;i<quality.size();i++)
            workers.push_back({(wage[i]*1.0)/quality[i], quality[i]});
        sort(workers.begin(), workers.end());
        double ans=DBL_MAX, quanSum=0;
        priority_queue<int> pq;
        for(auto worker:workers)
        {
            double ratio=worker.first;
            quanSum+=worker.second;
            pq.push(worker.second);
            if(pq.size()>k)
            {
                quanSum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
                ans=min(ans, quanSum*ratio);
        }
        return ans;
    }
};