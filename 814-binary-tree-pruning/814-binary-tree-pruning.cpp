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
    bool traverse(TreeNode* root)
    {
        if(!root)
            return false;
        bool left=traverse(root->left);
        bool right=traverse(root->right);
        if(left==false)
            root->left=NULL;
        if(right==false)
            root->right=NULL;
        return root->val==1 | left | right;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool t=traverse(root);
        if(!t)
            return NULL;
        return root;
    }
};