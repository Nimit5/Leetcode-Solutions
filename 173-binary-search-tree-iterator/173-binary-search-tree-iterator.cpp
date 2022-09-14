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
class BSTIterator {
private: stack<TreeNode*> ans;
public:
    
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* node=ans.top();
        ans.pop();
        // Push all right nodes of poped node
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !ans.empty();
    }
    void pushAll(TreeNode* root)
    {   
        // Push all left nodes of a given node in stack
        while(root!=NULL)
        {
            ans.push(root);
            root=root->left;
        }
    }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */