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
    int c=0;
    pair<int, int> solve(TreeNode *root)
    {
        if(root==NULL)
            return {0, 0};
        int subTreeSum=root->val;
        int subTreeNodeCount=1;
        pair<int, int> leftSubTree = solve(root->left);
        pair<int, int> rightSubTree = solve(root->right);
        subTreeSum+=leftSubTree.first + rightSubTree.first;
        subTreeNodeCount+=leftSubTree.second + rightSubTree.second;
        if (root->val == (subTreeSum/subTreeNodeCount))
            c++;
        return {subTreeSum, subTreeNodeCount};
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int, int> ans=solve(root);
        return c;
    }
};