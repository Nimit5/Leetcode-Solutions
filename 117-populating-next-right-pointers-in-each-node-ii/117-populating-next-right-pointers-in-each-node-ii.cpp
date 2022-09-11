/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        queue<Node *>nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            Node* prev=NULL;
            int s=nodes.size();
            for(int i=0;i<s;i++)
            {
                Node* temp=nodes.front();
                nodes.pop();
                if(temp->left)
                    nodes.push(temp->left);
                if(temp->right)
                    nodes.push(temp->right);
                if(i==0)
                    prev=temp;
                else if(prev!=NULL)
                {
                    prev->next=temp;
                    prev=temp;
                }
            }
        }
        return root;
    }
};