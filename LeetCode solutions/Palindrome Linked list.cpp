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
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *slow,*fast,*head2,*nxt,*prev,*curr;
        slow=head;
        fast=head;
        
        while(fast && fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        head2=slow->next;
        slow->next=NULL;
        
        prev=NULL;
        curr=head2;
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        head2=prev;
        
        while(head && head2)
        {
            if(head->val != head2->val)
            {
                return 0;
            }
            head=head->next;
            head2=head2->next;
        }
        return 1;
        
    }
};

///////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return check(head, head);
    }
    
    bool check(ListNode*& head, ListNode* p) {
        if(!p) { return true; }
        bool isPal = check(head, p->next);
        if(head->val != p->val) {
            return false;
        }
        head = head->next;
        return isPal;
    }
};