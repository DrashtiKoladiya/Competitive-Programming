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
    int solve(TreeNode* root,int &k)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int leftSub = solve(root->left,k);
        
        if(leftSub) return leftSub;
        k--;
        if(!k) return root->val;
        
        int rightSub = solve(root->right,k);
        return rightSub;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return solve(root,k);
    }
};