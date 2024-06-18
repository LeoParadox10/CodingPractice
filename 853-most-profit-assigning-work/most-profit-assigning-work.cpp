class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int i, j = 0, k = 0, n = profit.size();
        vector<pair<int, int>> v;
        for (i = 0; i < n; i++) {
            v.push_back({difficulty[i], profit[i]});
        }
        sort(v.begin(), v.end());
        j = 0;
        priority_queue<int> pq;
        sort(worker.begin(), worker.end());
        for (i = 0; i < worker.size(); i++) {
            while (j < n) {
                if (v[j].first > worker[i]) {
                    break;
                }
                pq.push(v[j].second);
                j++;
            }
            if (j > 0)
                k += pq.top();
        }
        return k;
    }
};