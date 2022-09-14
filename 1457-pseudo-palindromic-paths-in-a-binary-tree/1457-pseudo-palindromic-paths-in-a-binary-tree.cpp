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
    vector<int>v;
    bool check()
    {
        int odd=0;
        for(int i=1;i<=9;i++)
        {
            if(v[i]%2==1)
                odd++;
        }
        if(odd<=1)  return true;
        else return false;
    }
    void preorder(TreeNode *root)
    {
        if(!root)
            return;
        v[root->val]++;
        if(!root->left && !root->right)
        {
            if(check())
            {
                ans++;
                //cout<<root->val<<"\n";
            }
        }
        preorder(root->left);
        preorder(root->right);
        v[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        v.resize(10,0);
        preorder(root);
        return ans;
    }
};