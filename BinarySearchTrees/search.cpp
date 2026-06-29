/* problem link - https://leetcode.com/problems/search-in-a-binary-search-tree/description/ */
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL || root->val == val){
            return root;
        }

        if(root->val<val){
             return searchBST(root->right,val);
        }
        else if(root->val>val){
            return searchBST(root->left,val);
        }

        return NULL;
    }
};

//in bst 
// teh height is always log N to the base 2 
// using property of BST u solve this 
//inorder traversal of the BST will give the sorted array 