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
    map<pair<int,int>,vector<TreeNode*>> m;
    vector<TreeNode*> go(int start,int end)
    {
        vector<TreeNode*> v;
        if(m.find({start,end})!=m.end()) return m[{start,end}];
        if(start>end)
        {
            v.push_back(NULL);
            return m[{start,end}] = v ;
        }
        if(start==end)
        {
            TreeNode* root = new TreeNode(start);
            v.push_back(root);
            return m[{start,end}] = v;
        }
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> left = go(start,i-1);
            vector<TreeNode*> right = go(i+1,end);
            for(TreeNode* leftt:left)
            {
                for(TreeNode* rightt:right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftt;
                    root->right = rightt;
                    v.push_back(root);
                }
            }
        }
        return m[{start,end}] = v;
    }
    vector<TreeNode*> generateTrees(int n) {
        return go(1,n);
    }
};