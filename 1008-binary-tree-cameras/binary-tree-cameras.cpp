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

    int f(TreeNode *root, int &ans)
    {
        if(root==NULL)
            return -1;
        int l=f(root->left, ans);
        int r=f(root->right, ans);
        int k;
        if(l==-1)
        {
            if(r==-1)
                k=0;
            else if(r==0)
            {
                ans++;
                k=1;
            }
            else
                k=-1;
        }
        else if(l==0)
        {
            ans++;
            k=1;
        }
        else
        {
            if(r==-1)
                k=-1;
            else if(r==0)
            {
                ans++;
                k=1;
            }
            else
                k=-1;
        }
        return k;
    }

    int minCameraCover(TreeNode* root) {
        int ans=0;
        int x=f(root, ans);
        if(x==0)
            ans++;
        return ans;
    }
};