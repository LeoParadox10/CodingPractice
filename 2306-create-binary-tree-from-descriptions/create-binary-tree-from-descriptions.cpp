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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, bool> hasParent;

        for(auto desc:descriptions)
        {
            int parent=desc[0];
            int child=desc[1];
            int node=desc[2];
            TreeNode *parentNode=NULL;
            TreeNode *childNode=NULL;

            if(mp.find(parent)==mp.end())
                parentNode=new TreeNode(parent);
            else
                parentNode=mp[parent];

            if(mp.find(child)==mp.end())
                childNode=new TreeNode(child);
            else
                childNode=mp[child];

            // If node is left node
            if(node)
                parentNode->left=childNode;
            // If node is right node
            else
                parentNode->right=childNode;

            hasParent[child]=true;
            mp[child]=childNode;
            mp[parent]=parentNode;
        }
        TreeNode *root=NULL;
        for(auto& [nodeVal, node]:mp)
        {
            if(!hasParent[nodeVal])
                root=node;
        }
        return root;
    }
};