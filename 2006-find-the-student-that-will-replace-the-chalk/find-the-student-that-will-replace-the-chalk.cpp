class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(int x:chalk)
            sum+=x;
        int rem=k%sum;
        for(int i=0;i<chalk.size();i++)
        {
            rem=rem-chalk[i];
            if(rem<0)
                return i;
        }
        return -1;
    }
};