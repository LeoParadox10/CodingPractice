class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        s1+=" ";
        s2+=" ";
        unordered_map<string, int> mp;
        unordered_map<string, int> mp2;
        string w="";
        for(auto it:s1)
        {
            if(it!=' ')
                w+=it;
            else
            {
                if (!w.empty()) {
                    mp[w]++;
                    w="";
                }
            }
        }
        for(auto it:s2)
        {
            if(it!=' ')
                w+=it;
            else
            {
                if (!w.empty()) {
                    mp2[w]++;
                    w="";
                }
            }
        }
        vector<string> ans;
        for (auto it : mp) {
            if (it.second == 1 && mp2.find(it.first) == mp2.end()) {
                ans.push_back(it.first);
            }
        }
        for (auto it : mp2) {
            if (it.second == 1 && mp.find(it.first) == mp.end()) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};