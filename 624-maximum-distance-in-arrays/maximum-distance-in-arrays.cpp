class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n=arrays.size();
        int mini=arrays[0].front();
        int maxi=arrays[0].back();
        int max_dist=INT_MIN;
        for(int i=1;i<n;i++)
        {
            max_dist=max({max_dist, abs(arrays[i].back()-mini), abs(arrays[i].front()-maxi)});
            mini=min(mini, arrays[i].front());
            maxi=max(maxi, arrays[i].back());
        }
        return max_dist;
    }
};