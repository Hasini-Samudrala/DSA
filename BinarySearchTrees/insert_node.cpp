/*https://leetcode.com/problems/insert-into-a-binary-search-tree/ */

class SOlution{
    public:
    TreeNode* insertIntoBst(TreeNode* root, int val){
        if(root ==NULL){return new TreeNode(val);}

        if(root->val > val)
        root->left = insertIntoBst(root->left,val);

        else if(root->val<val)
        root->right = insertIntoBst(root->right,val);

        return root;
    }
};

/*in bst , the values less than the root are inserted into the left subtree where as the values greater than the root 
are inseryed in the right subtree 
we check if teh given value is less or greater than the root in the recursive way and identify
*/