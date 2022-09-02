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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        if(!root) return ans;
        q.push(root);
        while(!q.empty())
        {
            double temp=0.0;
            double l=q.size();
            //cout<<"Initial Queue size = "<<l<<"\n";
            for(double i=0;i<l;i++)
            {
                TreeNode *node=q.front();
                temp+=(double)node->val;
                //cout<<"Temp = "<<temp<<"\n";
                q.pop();
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
            temp/=l;
            ans.push_back(temp);
        }
        return ans;
    }
};