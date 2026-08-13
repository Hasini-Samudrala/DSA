/*probelm link - https://leetcode.com/problems/binary-search-tree-iterator/ */

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
class BSTIterator {
private:
    stack<TreeNode*>myStack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }

    void pushAll(TreeNode* root){
        while(root!=NULL){
            myStack.push(root);
            root = root->left;
        }

    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


 /*
 basically we do the inorder , but we dont store it , 
 we just use a stack and maintain the inorder 
 and the size of the stack would always be less or equal to the height of the tree 
 
 so for the next is the we need to return the next element in the inorder traversal , so while popping the elements from the
 stack we need to push the elements anyhting present to the right of it 
 so we push them and return the value of the node 

 whereas hasNext is like to check if there is any element next to it .. basically it is like only for the last element it would 
 be false .. for the remaining elements it would be tru =e only .
 
 */