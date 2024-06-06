class Solution {
public:
    bool f(vector<int> &hand, int groupSize, int ind, int n)
    {
        int next=hand[ind]+1;
        hand[ind]=-1;
        int c=1;
        ind++;
        while(ind<n && c<groupSize)
        {
            if(hand[ind]==next)
            {
                next=hand[ind]+1;
                hand[ind]=-1;
                c++;
            }
            ind++;
        }
        return c==groupSize;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)
            return false;
        sort(hand.begin(), hand.end());
        for(int i=0;i<n;i++)
        {
            if(hand[i]>=0)
                if(!f(hand, groupSize, i, n))
                    return false;
        }
        return true;
    }
};