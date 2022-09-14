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
    vector<vector<int>>ans;
    vector<int>temp;
    int s=0;
    void preorder(TreeNode* root, int target)
    {
        if(!root)   return;
        s+=root->val;
        temp.push_back(root->val);
        if(!root->left and !root->right)
        {
            if(s==target)
                ans.push_back(temp);
        }
        preorder(root->left,target);
        preorder(root->right,target);
        s-=root->val;
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        preorder(root,targetSum);
        return ans;
    }
};