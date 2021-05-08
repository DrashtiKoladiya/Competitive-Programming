/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* find(TreeNode*node, int p,int q)
    {
        if(node==NULL)
        {
            return NULL;
        }
        
        if(node->val == p || node->val == q)
        {
            return node;
        }
          
        TreeNode *leftNode,*rightNode;
        leftNode = find(node->left,p,q);
        rightNode = find(node->right,p,q);
        if(leftNode!=NULL && rightNode!=NULL)
        {
            return node;
        }
        
        return leftNode!=NULL?leftNode:rightNode;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root,p->val,q->val);
    }
};