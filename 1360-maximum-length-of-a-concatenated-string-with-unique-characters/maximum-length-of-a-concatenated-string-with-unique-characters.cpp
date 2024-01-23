class Solution {
private:
    bool solve(const string &st)
    {
        unordered_set<char> s;
        for(auto c:st)
        {
            if(s.count(c))
                return false;
            s.insert(c);
        }
        return true;
    }
    void dfs(int &ans, const vector<string> &arr, const string &path, int idx)
    {
        if(solve(path))
            ans=max(ans, static_cast<int>(path.length()));
        if(idx==arr.size() || !solve(path))
            return;
        for(int i=idx;i<arr.size();i++)
            dfs(ans, arr, path+arr[i], i+1);
    }
public:
    int maxLength(vector<string>& arr)
    {
        int ans = 0;
        dfs(ans, arr, "", 0);
        return ans;
    }
};