class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> p;
        for(auto i:happiness)
            p.push(i);
        long long ans=0;
        int c=0;
        for(int i=0;i<k;i++)
        {
            ans+=max(p.top()-c, 0);
            p.pop();
            c++;
        }
        return ans;
    }
};