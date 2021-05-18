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
    
    ListNode* merge(ListNode* head)
    {
        if(head==NULL || head->next==NULL) return head;
        
        if(head->next->next==NULL)
        {
            if(head->val <= head->next->val) return head;
            else
            {
                ListNode *tmp=head->next;
                head->next->next=head;
                head->next=NULL;
                head=tmp;
            }
        }
        
        ListNode* fast,*slow,*h1,*h2;
        slow=head;
        fast=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        fast=slow->next;
        slow->next=NULL;
        h1 = merge(head);
        h2 = merge(fast);
        
        if(h1==NULL) return h2;
        if(h2==NULL) return h1;
        
        ListNode *dummy=new ListNode,*fake;
        fake = dummy;
        while(h1 && h2)
        {
            if(h1->val > h2->val)
            {
                fake->next = h2;
                fake = fake->next;
                h2 = h2->next;
            }
            else
            {
                fake->next = h1;
                fake = fake->next;
                h1=h1->next;
            }
        }
        
        if(h1) fake->next=h1;
        if(h2) fake->next=h2;
        
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        return merge(head);
    }
};