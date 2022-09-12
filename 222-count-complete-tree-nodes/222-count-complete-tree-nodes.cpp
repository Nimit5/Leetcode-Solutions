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
    int ans=0;
    void preorder(TreeNode *root)
    {
        if(!root)   return;
        ans++;
        preorder(root->left);
        preorder(root->right);
    }
    int countNodes(TreeNode* root) {
        preorder(root);
        return ans;
    }
};