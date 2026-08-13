/*problem link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/ */

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
    vector<int> arr;
    void inorder(TreeNode* root)
    {
        if(!root) return ;

        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);

        return ;
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);

        return arr[k-1];
    }
};

/*intution
Initialize an empty vector 'v'.
Do an Inorder traversal and store the node values in v.
Return v[k-1].
*/