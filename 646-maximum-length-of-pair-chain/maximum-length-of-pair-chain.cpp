class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1]<b[1];
        });
        int curr=INT_MIN;
        int ans=0;
        for(const auto &pair:pairs)
        {
            if(curr<pair[0])
            {
                curr=pair[1];
                ans++;
            }
        }
        return ans;
    }
};