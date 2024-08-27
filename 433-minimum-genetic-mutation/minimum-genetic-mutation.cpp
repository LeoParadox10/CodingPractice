class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        unordered_set<string> s;
        for(auto it:bank)
            s.insert(it);
        if(s.find(endGene)==s.end())
            return -1;
        vector<char> v;
        v.push_back('A');
        v.push_back('C');
        v.push_back('G');
        v.push_back('T');
        while(!q.empty())
        {
            string st=q.front().first;
            int level=q.front().second;
            q.pop();
            if(st==endGene)
                return level;
            for(int i=0;i<st.size();i++)
            {
                string str=st;
                for(char ch:v)
                {
                    st[i]=ch;
                    if(s.find(st)!=s.end())
                    {
                        q.push({st, level+1});
                        s.erase(st);
                    }
                }
                st=str;
            }
        }
        return -1;
    }
};