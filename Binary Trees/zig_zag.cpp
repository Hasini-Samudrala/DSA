/* problem link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/ */
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;
        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                int index = (leftToRight) ? i:(size-1-i);
                row[index] = node->val;

                if(node->left){
                    nodesQueue.push(node->left);
                }
                if(node->right){
                    nodesQueue.push(node->right);
                }
            }
            leftToRight = !(leftToRight);
            ans.push_back(row);
        }

        return ans;
    }
};

// same as the level irder traversal 
// but here you should go from left toright in the first level and right to left in the second level 
// so you maintain a flag and accordingly you chnage the index of inserting into the row which is inserted to the answer at the last 