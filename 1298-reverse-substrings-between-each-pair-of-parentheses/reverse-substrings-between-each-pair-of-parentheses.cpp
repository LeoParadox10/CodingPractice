class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        string ans="";
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')')
            {
                int u=st.top()+1;
                st.pop();
                int v=i;
                reverse(s.begin()+u, s.begin()+v);
            }
        }
        for(char c:s)
        {
            if(c=='(' || c==')')
                continue;
            else
                ans+=c;
        }
        return ans;
    }
};