/* problem link - https://leetcode.com/problems/binary-tree-right-side-view/description/ */
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
    void recursion(TreeNode* root, int level , vector<int> &res){
        if(root ==NULL) return ;

        if(level == res.size()){
            res.push_back(root->val);
        }
        recursion(root->right,level+1,res);
        recursion(root->left,level+1,res);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root,0,res);
        return res;
    }
};

//so u traverse root right left 
// everytime u visit the level for the first time , u add that into ur data structure 
// most imp thinig , u shoudl semd &res not normal res