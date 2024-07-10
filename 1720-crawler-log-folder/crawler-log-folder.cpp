class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(auto it:logs)
        {
            if(it[0]!='.')
                ans++;
            else if(it[1]!='/')
                ans--;
            if(ans<0)
                ans=0;
        }
        if(ans<=0)
            return 0;
        return ans;
    }
};