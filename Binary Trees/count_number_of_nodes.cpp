/*problem link - https://leetcode.com/problems/count-complete-tree-nodes/ */

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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if(lh==rh) return (1<<lh)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }

    int findLeftHeight(TreeNode * node){
        int height=0;
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }

    int findRightHeight(TreeNode* node){
        int height =0;
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }
};

/*intution 
so complete binary tree - all the nodes in the last level have to be to the atmost left side 
to find teh number of nodes when it is full is just doing 2 power height of the tree and -1
but always the treee wont be full 
so what we do is to calculate the heght for the subtress which qare full 
so how do we know that 
we calcuate the left and right subtree ka height and if they turn out to be equal which means that
the tree is full but if not 
then we go one level down and then check there 
this happens recursively 
*/