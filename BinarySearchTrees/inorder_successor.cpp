/* problem link - https://leetcode.com/problems/inorder-successor-in-bst/description/ 
check striver video since this is premium subsricption question */

class Solution{
    public:
    TreeNode* inorderSuccessor(TreeNode* root , TreeNode* p){
        TreeNode* successor = NULL;
        while(!root){
            if(p->val >= root->val){
                root = root->right;
            }
            else{
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }
};