class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int windowSum=0, zeroSum=0, maxWindowSum=0, n=customers.size();
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
                zeroSum+=customers[i];
            if(i<minutes)
                windowSum+=(grumpy[i]==1?customers[i]:0);
            else
            {
                if(grumpy[i]==1)
                    windowSum+=customers[i];
                if(grumpy[i-minutes]==1)
                    windowSum-=customers[i-minutes];
            }
            maxWindowSum=max(maxWindowSum, windowSum);
        }
        return maxWindowSum+zeroSum;
    }
};