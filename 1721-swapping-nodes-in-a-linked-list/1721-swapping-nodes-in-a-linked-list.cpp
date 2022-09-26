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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *fast = head, *slow = head,*curr;
        for (int i = 1; i < k; i++) fast = fast->next;
        if (!fast) return head->next;
        //cout<<fast->val<<"\n";
        curr=fast;
        while (fast->next) fast = fast->next, slow = slow->next;
        swap(slow->val,curr->val);
        return head;
    }
};