class Solution {
public:
    int parent[26];
    int find(int u)
    {
        return parent[u]==u?u:find(parent[u]);
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i=0;i<26;i++)
            parent[i]=i;
        for(int i=0;i<s1.size();i++)
        {
            int u=find(s1[i]-'a');
            int v=find(s2[i]-'a');
            if(u<v)
                parent[v]=u;
            else if(u>v)
                parent[u]=v;
            else
                continue;
        }
        for(int i=0;i<baseStr.size();i++)
            baseStr[i]=(char)(find(baseStr[i]-'a')+'a');
        return baseStr;
    }
};