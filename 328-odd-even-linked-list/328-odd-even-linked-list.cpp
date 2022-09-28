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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return head;
        ListNode *e_head=NULL,*e_tail=NULL,*o_tail=NULL,*o_head=NULL,*curr=head;
        vector<int>flag;
        int i=0;
        while(curr)
        {
            if(i%2==0)
            {
                if(e_head==NULL)
                {
                    flag.push_back(0);
                    e_head=curr;
                    e_tail=curr;
                }
                else
                {
                    e_tail->next=curr;
                    e_tail=e_tail->next;
                }
            }
            else
            {
                if(o_head==NULL)
                {
                    flag.push_back(1);
                    o_head=curr;
                    o_tail=curr;
                }
                else
                {
                    o_tail->next=curr;
                    o_tail=o_tail->next;
                }
            }
            curr=curr->next;
            i++;
        }
        if(flag[0]==0)
        {
            if(e_tail)
                e_tail->next=o_head;
            if(o_tail)
                o_tail->next=NULL;
            return e_head?e_head:o_head;
        }
        else
        {
            if(o_tail)
                o_tail->next=e_head;
            if(e_tail)
                e_tail->next=NULL;
            return o_head?o_head:e_head;
        }
        
    }
};
// 1 2 3 4 5
// 