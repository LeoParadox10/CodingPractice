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
    unordered_map<int, int> dfs(TreeNode *node, int &dis, int &noOfGoodLeafPairs)
    {
        if(node==NULL)
            return {};
        unordered_map<int, int> mp;
        mp[1]=1;
        if(node->left==NULL && node->right==NULL)
            return mp;
        unordered_map<int, int> leftv=dfs(node->left, dis, noOfGoodLeafPairs);
        unordered_map<int, int> rightv=dfs(node->right, dis, noOfGoodLeafPairs);
        for(auto [lv, lf]:leftv)
        {
            for(auto [rv, rf]:rightv)
            {
                if(lv+rv<=dis)
                    noOfGoodLeafPairs+=(lf*rf);
            }
        }
        unordered_map<int, int> parentv;
        for(auto [lv, lf]:leftv)
        {
            if(lv+1<=dis)
                parentv[lv+1]+=lf;
        }
        for(auto [rv, rf]:rightv)
        {
            if(rv+1<=dis)
                parentv[rv+1]+=rf;
        }
        return parentv;
    }
    int countPairs(TreeNode* root, int distance) {
        int noOfGoodLeafPairs=0;
        dfs(root, distance, noOfGoodLeafPairs);
        return noOfGoodLeafPairs;
    }
};