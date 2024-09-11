class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xori=start^goal;
        int ans=0;
        while(xori>0)
        {
            ans+=xori&1;
            xori=xori>>1;
        }
        return ans;
    }
};