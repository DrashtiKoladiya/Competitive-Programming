#include<stdlib.h>
#include<iostream>
using namespace std;

/*
--Node is defined as--
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    } 
};
*/

class Solution
{
    public:
    void linkdelete(struct Node  *head, int m, int n)
    {
        Node *prev1,*prev2;
        int f=0,x;
        
        prev1=head;
        if(n==0) return;
        else if(m==0) 
        {
            head=NULL;
            if(head->next) head->next=NULL;
            return;
        }
        while(prev1!=NULL && prev1->next!=NULL)
        {
            if(f==0)
            {
                x=m-1;
                while(x-- && prev1->next!=NULL)
                {
                    prev1=prev1->next;
                }
                
                if(prev1->next==NULL)
                {
                    break;
                }
                prev2=prev1->next;
                f=1;
            }
            else
            {
                x=n-1;
                while(x-- && prev2->next!=NULL)
                {
                    prev2=prev2->next;
                }
                
                prev1->next = prev2->next;
                prev1 = prev1->next;
                f=0;
            }
        }
    }
};

