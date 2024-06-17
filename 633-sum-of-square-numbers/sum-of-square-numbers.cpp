class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0;i<=sqrt(c);i++)
        {
            int x=c-(i*i);
            if(x<0)
                return false;
            int y=sqrt(x);
            if(y*y==x)
                return true;
        }
        return false;
    }
};