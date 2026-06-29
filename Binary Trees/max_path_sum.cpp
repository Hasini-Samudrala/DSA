/* problem link  - https://leetcode.com/problems/binary-tree-maximum-path-sum/description/ */
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
    int maxPathSum(TreeNode* root) {
         int maxi = INT_MIN;
         maxPath(root,maxi);
         return maxi;
    }

private:
    int maxPath(TreeNode* root , int &maxi){
        if(root==NULL){
            return 0;
        }
        int leftSum = max(0,maxPath(root->left,maxi));
        int rightSum = max(0,maxPath(root->right,maxi));
        maxi = max(maxi,leftSum+rightSum+root->val);

        return root->val+max(leftSum,rightSum);
    }
};

// similar to finding teh height of the tree 
// at every node you calculate the max if its children are taken and store that 