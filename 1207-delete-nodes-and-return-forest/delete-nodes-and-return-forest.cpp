/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *dfs(TreeNode *&root, unordered_set<int> &st, vector<TreeNode *> &ans)
    {
        if(root==NULL)
            return NULL;
        root->left=dfs(root->left, st, ans);
        root->right=dfs(root->right, st, ans);
        if(st.find(root->val)!=st.end())
        {
            if(root->left!=NULL)
                ans.push_back(root->left);
            if(root->right!=NULL)
                ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode *> ans;
        if (dfs(root, st, ans) != nullptr)
            ans.push_back(root);
        sort(ans.begin(), ans.end());
        return ans;
    }
};