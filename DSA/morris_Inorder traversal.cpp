void MorisInorder(TreeNode* root) {
        TreeNode*curr=root;
        vector<int> inOrder;
        while(curr)
        {
            if(curr->left==NULL)
            {
                inOrder.push_back(curr->val);
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
                    inOrder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
}