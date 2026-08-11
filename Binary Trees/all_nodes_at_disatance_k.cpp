/*problem link - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/ */

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
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent_track,TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * currentNode = q.front();
            q.pop();

            if(currentNode->left){
            parent_track[currentNode->left] = currentNode;
            q.push(currentNode->left);
            }
            if(currentNode->right){
            parent_track[currentNode->right] = currentNode;
            q.push(currentNode->right);
            }
        }
    } 
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent_track;
        markParents(root, parent_track,target);

        unordered_map<TreeNode*, bool>vis;

        queue<TreeNode*>q;
        q.push(target);
        vis[target] = true;

        int curr_level = 0; //distance

        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k)
            break;

            for(int i =0;i<size;i++){
                TreeNode * current = q.front();
                q.pop();

                if(current->left && !vis[current->left])
                {
                    q.push(current->left);
                    vis[current->left] = true;
                }
                if(current->right && !vis[current->right]){
                    q.push(current->right);
                    vis[current->right] = true;
                }

                if(parent_track[current] && !vis[parent_track[current]]){
                    q.push(parent_track[current]);
                    vis[parent_track[current]] = true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* current = q.front();

            ans.push_back(current->val);
            q.pop();
        }
        return ans;
    }
};

/*intution 
First store every node's parent because a normal binary tree cannot move upward. Then start BFS from the 
target and explore left, right, and parent. Use visited to avoid going back and forth. When BFS reaches 
level K, all nodes currently in the queue are the answer.*/