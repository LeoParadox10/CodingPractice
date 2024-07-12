class Solution {
private:
    pair<string, int> removeLetters(string s, string target, int pnt)
    {
        stack<char> st;
        int ans=0;
        for(char c:s)
        {
            if(!st.empty() && st.top()==target[0] && c==target[1])
            {
                ans+=pnt;
                st.pop();
            }
            else
                st.push(c);
        }
        string temp="";
        while(!st.empty())
        {
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return {temp, ans};
    }
public:
    int maximumGain(string s, int x, int y) {
        string ab="ab", ba="ba";
        if(x<y)
            swap(x, y), swap(ab, ba);
        auto it1=removeLetters(s, ab, x);
        auto it2=removeLetters(it1.first, ba, y);
        return it1.second+it2.second;
    }
};