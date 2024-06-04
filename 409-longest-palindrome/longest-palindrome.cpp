class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> st;
        int ans=0;
        for(auto c:s)
        {
            if(st.find(c)!=st.end())
            {
                st.erase(c);
                ans+=2;
            }
            else
                st.insert(c);
        }
        if(!st.empty())
            ans++;
        return ans;
    }
};