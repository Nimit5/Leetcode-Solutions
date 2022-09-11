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
    vector<int> helper(TreeNode *root, int d, int &ans)
    {
        if(!root)   return {0};
        if(!root->left and !root->right)    return {1};
        vector<int> l=helper(root->left,d,ans);
        vector<int> r=helper(root->right,d,ans);
        for(auto a:l)
        {
            for(auto b:r)
            {
                if((a and b) and a+b<=d)
                    ans++;
            }
        }
        vector<int>ret;
        for(auto a:l)
        {
            if(a and a+1<d)ret.push_back(a+1);
        }
        for(auto b:r)
        {
            if(b and b+1<d)ret.push_back(b+1);
        }
        return ret;
    }
    int countPairs(TreeNode* root, int distance) {
        int ans=0;
        helper(root,distance,ans);
        return ans;
    }
};