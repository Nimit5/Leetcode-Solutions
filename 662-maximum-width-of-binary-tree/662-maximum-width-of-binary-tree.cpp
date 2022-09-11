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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans=0;
        queue<pair<TreeNode*,long long>> nodes;
        nodes.push({root,0});
        while(!nodes.empty())
        {
            long long s=nodes.size();
            long long mini=nodes.front().second;
            long long first,last,curr;
            for(int i=0;i<s;i++)
            {
                TreeNode* temp=nodes.front().first;
                curr=nodes.front().second-mini;
                nodes.pop();
                if(i==0)
                    first=curr;
                if(i==s-1)
                    last=curr;
                if(temp->left)
                    nodes.push({temp->left,curr*2+1});
                if(temp->right)
                    nodes.push({temp->right,curr*2+2});
            }
            if(ans<last-first+1)
                ans=last-first+1;
        }
        return ans;
    }
};