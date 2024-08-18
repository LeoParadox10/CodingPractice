class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> s;
        long ans=1;
        s.insert(ans);
        for(int i=0;i<n;i++)
        {
            ans=*s.begin();
            s.erase(ans);
            s.insert(ans*2);
            s.insert(ans*3);
            s.insert(ans*5);
        }
        return ans;
    }
};