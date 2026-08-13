class Solution{
    public:
    TreeNode* deleteNode(TreeNode* root, int key){
        if(!root) return nullptr;

        if(root->val>key)
        deleteNode(root->left,key);

        else if(root->val<key)
        deleteNode(root->right,key);

        else{
            if(!root->right) return root->left;
            if(!root->left) return root->right;

            TreeNode* pred = root->left;
            while(pred->right){
                pred =  pred->right;
            }

            root->val = pred->val;
            root->left = deleteNode(root->left,pred->val);
        }
        return root;
    }
};


/*1. Search for key using BST property.

2. If node has 0 children:
      return NULL

3. If node has 1 child:
      return that child

4. If node has 2 children:
      find inorder predecessor
      copy predecessor's value
      delete the original predecesso
      
      The part you REALLY need to remember:
TreeNode* pred = root->left;

while(pred->right)
    pred = pred->right;

means:

Go to the left subtree, then keep going right → largest value smaller than the current node.

Then:

root->val = pred->val;
root->left = deleteNode(root->left, pred->val);

means:

Copy predecessor into the node I'm deleting, then remove the duplicate predecessor from the left subtree.
*/