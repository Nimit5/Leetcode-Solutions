/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL,*next=head;
        while(next!=NULL)
        {
            cout<<head->val<<" ";
            next=head->next;
            //cout<<next->val<<" ";
            head->next=prev;
            prev=head;
            if(next!=NULL)
                head=next;
        }
        return head;
    }
};