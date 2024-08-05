class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int c=0;
        int n=arr.size();
        unordered_map<string, int> mp;
        for(auto it:arr)
            mp[it]++;
        for(int i=0;i<n;i++)
        {
            if(mp[arr[i]]==1)
            {
                c++;
                if(c==k)
                    return arr[i];
            }
        }
        return "";
    }
};