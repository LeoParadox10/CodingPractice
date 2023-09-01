class Solution {
public:
    int solve(int n)
    {
        int c = 0;
        while (n) {
            c += n & 1;
            n >>= 1;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            ans.push_back(solve(i));
        }
        return ans;
    }
};