class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans=0;
        vector<int> freq(26, 0);
        for(auto ch:allowed)
            freq[ch-'a']++;
        for(auto word:words)
        {
            ans++;
            for(auto ch:word)
            {
                if(freq[ch-'a']==0)
                {
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};