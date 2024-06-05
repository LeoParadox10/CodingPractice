class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> v(26, INT_MAX);
        for (auto& word : words) {
            vector<int> freq(26, 0);
            for(char c:word)
                freq[c-'a']++;
            for(int i=0;i<26;i++)
                v[i]=min(v[i], freq[i]);
        }
        vector<string> ans;
        for(int i=0;i<26;i++)
        {
            while(v[i]--)
                ans.push_back(string(1, i+'a'));
        }
        return ans;
    }
};