/*problem link  - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/  */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root ==p || root ==q)
        return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left == NULL){
            return right;
        }
        else if(right == NULL)
        return left;

        else 
        return root;
    }
};

//lca(p,q)
// so u always go recursively here 
// when u find teh node that u are searching for then you return that else u return null
// if any one is null, you return the other , basically u didnt find in that path , so we choose the other 
// both are null then also null 
// if both are not null then bingo , e found teh lowest common ancestor 