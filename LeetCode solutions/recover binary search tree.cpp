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
class Solution {
public:
    TreeNode *wrongnode1=NULL,*wrongnode2=NULL,*prev=NULL;
    void verify(TreeNode* curr)
    {
        if(prev && (prev->val > curr->val))
        {
            if(!wrongnode1)
            {
                wrongnode1=prev;
                wrongnode2=curr;
            }
            else
            {
                wrongnode2=curr;
            }
        }
        prev=curr;
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode*curr=root;
        while(curr)
        {
            if(curr->left==NULL)
            {
                verify(curr);
                curr=curr->right;
            }
            else
            {
                TreeNode *preProcessor=curr->left;
                while(preProcessor->right && (preProcessor->right)!=curr)
                {
                    preProcessor=preProcessor->right;
                }
                
                if(preProcessor->right==NULL)
                {
                    preProcessor->right=curr;
                    curr=curr->left;
                }
                else
                {
                    preProcessor->right=NULL;
                    verify(curr);
                    curr=curr->right;
                }
            }
        }
        
        swap(wrongnode1->val,wrongnode2->val);
    }
};