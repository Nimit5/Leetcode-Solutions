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
    void solve(TreeNode* root, int k, map<int,int>&mp, bool &flag)
    {
        if(!root)
            return;
        if(flag)
            return;
        solve(root->left,k,mp,flag);
        if(mp.find((k-root->val))!=mp.end())
        {
            flag=true;
            return;
        }
        else
        {
            mp[root->val]++;
        }
        solve(root->right,k,mp,flag);
    }
    bool findTarget(TreeNode* root, int k) {
        map<int,int>mp;
        bool flag=false;
        solve(root,k,mp,flag);
        return flag;
    }
};