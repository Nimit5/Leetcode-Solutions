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
private:
	bool isSameList(ListNode *node0, ListNode *node1) {
		while(node0 && node1) {
			if (node0->val != node1->val) return false;
			node0 = node0->next;
			node1 = node1->next;
		}
		//if (node0 || node1) return false;
		return true;
	}
public:
    bool isPalindrome(ListNode* head) {
        ListNode *pre = NULL, *fast = head, *slow = head;
        while(fast && fast->next) {		//reverse list
        	fast = fast->next->next;
        	ListNode *tmp = slow;
        	slow = slow->next;
        	tmp->next = pre;
        	pre = tmp;
        }
        if(fast != NULL) {
        	slow = slow->next;
        }
        return isSameList(pre, slow);
    }
};