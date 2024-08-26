/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    void f(Node *root)
    {
        if(root==NULL)
            return;
        for(auto child:root->children)
        {
            f(child);
            ans.push_back(child->val);
        }
    }
    vector<int> postorder(Node* root) {
        if(root==NULL)
            return {};
        f(root);
        if(root!=NULL)
            ans.push_back(root->val);
        return ans;
    }
};