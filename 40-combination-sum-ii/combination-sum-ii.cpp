class Solution {
public:
    void dfs(vector<int>& candidates, int curr, int target, vector<int> &path, vector<vector<int>> &ans)
    {
        if(target<0)
            return;
        if(target==0)
        {
            ans.push_back(path);
            return;
        }
        for(int i=curr;i<candidates.size();i++)
        {
            if(i>curr && candidates[i]==candidates[i-1])
                continue;
            path.push_back(candidates[i]);
            dfs(candidates, i+1, target-candidates[i], path, ans);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        dfs(candidates, 0, target, path, ans);
        return ans;
    }
};