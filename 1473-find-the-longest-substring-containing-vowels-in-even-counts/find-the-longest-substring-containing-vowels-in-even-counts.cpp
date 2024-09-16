class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> vowelPos={{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        unordered_map<int, int> last;
        last[0]=-1;
        int curr=0;
        int maxi=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                curr^=(1<<vowelPos[s[i]]);
            if(last.find(curr)!=last.end())
                maxi=max(maxi, i-last[curr]);
            else
                last[curr]=i;
        }
        return maxi;
    }
};