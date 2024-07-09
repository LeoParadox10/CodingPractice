class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double service=customers[0][0]+customers[0][1];
        double wait=customers[0][1];
        for(int i=1;i<n;i++)
        {
            if(service<customers[i][0])
                service=customers[i][0];
            service+=customers[i][1];
            wait+=service-customers[i][0];
        }
        return wait/n;
    }
};