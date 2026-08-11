/* problem link - https://leetcode.com/problems/diameter-of-binary-tree/description/ */

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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root,diameter);
        return diameter;
    }
private:
    int height(TreeNode* root, int &diameter){
        if(!root) return 0;

        int lh = height(root->left,diameter);
        int rh = height(root->right,diameter);

        diameter = max(diameter, lh+rh);
        return 1+max(lh,rh);
    }
};

//just add a line diamter = max(diameter seen so far , or the lh+rh seen now) in the problem depth of binary tree 
//The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
// This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.
