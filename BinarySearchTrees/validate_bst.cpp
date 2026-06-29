/* problem link - https://leetcode.com/problems/validate-binary-search-tree/description/ */
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
    bool check(TreeNode* root, long long l , long long r){
        if(root==NULL) return true;

        if(root->val<=l || root->val>=r ) return false;

        return check(root->left,l,root->val) && check(root->right,root->val,r);
    }
    bool isValidBST(TreeNode* root) {
        return check(root,LONG_MIN,LONG_MAX);
    }
};

//using bst property 
// everytime you gp left , it should be less than the root, everytime you go right 
// it should be grate thna the root 
// so you basically send the range in terms of l and r to teh helper function 
// so we check if the presnet root ka value is lying in that range , if yes proceed to the next 
// if not return false there only 