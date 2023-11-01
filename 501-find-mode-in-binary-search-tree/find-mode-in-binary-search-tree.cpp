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
    void inorder(TreeNode *root, vector<int> &temp)
    {
        if(root==NULL)
            return;
        inorder(root->left, temp);
        temp.push_back(root->val);
        inorder(root->right, temp);
    }
    vector<int> findMode(TreeNode* root)
    {
        vector<int> temp;
        inorder(root, temp);
        unordered_map<int, int> freq;
        int maxi=0;
        for(auto val:temp)
        {
            freq[val]++;
            maxi=max(maxi, freq[val]);
        }
        vector<int> ans;
        for(auto &pair:freq)
            if(pair.second==maxi)
                ans.push_back(pair.first);
        return ans;
    }
};