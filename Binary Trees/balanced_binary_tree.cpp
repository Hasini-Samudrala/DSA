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
    bool isBalanced(TreeNode* root) {
        int check = height(root);
        if(check == -1) return false;
        else return true;
    }
    private:
        int height(TreeNode* root){
            if(root == NULL) return 0;

            int lh = height(root->left);
            int rh = height(root->right);

            if(lh == -1 || rh ==-1) return -1;
            if( abs(lh-rh)>1) return -1;

            return max(lh,rh)+1;
        }
};

// for a Balances binary tree , at every node the height(left sub tree ) - height(right sub tree) should be less than or equal to 1
// so similar to the depth or height problem , we just return -1 anytime we encounter anything against , else we just return teh height of the tree