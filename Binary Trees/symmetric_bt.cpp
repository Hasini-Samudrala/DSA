/*
problem link - https://leetcode.com/problems/symmetric-tree/description/ 
*/

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
    bool isSymmetric(TreeNode* root) {
        return root==NULL || isSymmetricHelp(root->left,root->right);
    }

    bool isSymmetricHelp(TreeNode* rootLeft,TreeNode* rootRight){
        if(rootLeft == NULL || rootRight==NULL){
            return rootLeft == rootRight;
        } 

        if(rootLeft->val != rootRight->val) return false;

        return isSymmetricHelp(rootLeft->left,rootRight->right) && isSymmetricHelp(rootLeft->right,rootRight->left);
    }
};

//symmetric binary tree
// left subtree ka right has to match with right subtree ka left 
// we perform this action recursively 