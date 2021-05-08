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

//method based on merge sort
class Solution {
public:
    
    ListNode* merge(vector<ListNode*>& lists,int l,int r)
    {
        if(l==r) return lists[l];
        
        int mid=l+(r-l)/2;
        ListNode *head=new ListNode(),*a1,*a2,*curr;
        a1 = merge(lists,l,mid);
        a2 = merge(lists,mid+1,r);
        
        if(a1==NULL) return a2;
        if(a2==NULL) return a1;
        
        curr=head;
        while(a1!=NULL && a2!=NULL)
        {
            if(a1->val < a2->val)
            {
                curr->next = a1;
                curr = curr->next;
                a1 = a1->next;
            }
            else
            {
                curr->next = a2;
                curr = curr->next;
                a2 = a2->next;
            }
        }
        
        if(a1) curr->next = a1;
        if(a2) curr->next = a2;
        
        return head->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n=lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];
        
        return merge(lists,0,n-1);
        
    }
};

//method based on heap/min_priority queue
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
    
    struct node{
        ListNode *curr; 
        int idx;
        
        node(ListNode *c,int id)
        {
            curr=c;
            idx=id;
        }
    };
    
    struct compare{
        bool operator()(node a, node b)
        {
            return a.curr->val > b.curr->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n=lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];
        
        ListNode *head=new ListNode(),*curr;
        
        priority_queue<node,vector<node>,compare> heap;
        
        for(int i=0;i<n;i++)
        {
            if(lists[i]!=NULL) heap.push(node(lists[i],i));
        }
        
        curr=head;
        while(!heap.empty())
        {
            node tmp = heap.top();
            int id=heap.top().idx;
            
            curr->next = tmp.curr;
            curr = curr->next;
            
            heap.pop();
            
            if(lists[id]!=NULL)
            {
                lists[id]=lists[id]->next;
                if(lists[id]!=NULL)
                {
                    heap.push(node(lists[id],id));
                }
            }
        }
        
        return head->next;
        
    }
};