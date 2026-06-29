/*Problem lInk - https://leetcode.com/problems/binary-tree-preorder-traversal/description/*/
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
vector<int> preorder;
    vector<int> preorderTraversal(TreeNode* node) {
        if(node == NULL){
            return {} ;
        }

        preorder.push_back(node->val);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
        return preorder;

    }
};

//preoder - root left right 
// recursive approach 