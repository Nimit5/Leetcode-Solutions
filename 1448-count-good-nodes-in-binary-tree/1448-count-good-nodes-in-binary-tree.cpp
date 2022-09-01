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
    int goodNodes(TreeNode* root) {
        int maxi=INT_MIN; 
        return dfs(root,maxi);
    }
    int dfs(TreeNode* root, int maxi)
    {
        if(!root) return 0;
        if(root->val>=maxi)
            return 1+dfs(root->left,root->val)+dfs(root->right,root->val);
        else
            return dfs(root->left,maxi)+dfs(root->right,maxi);
    }
};