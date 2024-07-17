class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        int carry=0;
        while(b!=0)
        {
            ans=a^b;
            carry=a&b;
            carry=carry<<1;
            a=ans;
            b=carry;
        }
        return a;
    }
};