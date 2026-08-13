/*problem link - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/ */

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
    stack<TreeNode*> myStack;
    bool reverse;

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();

        if (!reverse)
            pushAll(tmpNode->right);
        else
            pushAll(tmpNode->left);

        return tmpNode->val;
    }

private:
    void pushAll(TreeNode* node) {
        for (; node != NULL;) {
            myStack.push(node);

            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        if (!root)
            return false;

        // Normal inorder → smallest to largest
        BSTIterator l(root, false);

        // Reverse inorder → largest to smallest
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while (i < j) {

            if (i + j == k)
                return true;

            else if (i + j < k)
                i = l.next();

            else
                j = r.next();
        }

        return false;
    }
};

/*inutution
Use one inorder iterator to get the next smallest element and one reverse-inorder iterator to get the next largest element;
 move the appropriate iterator based on whether their sum is smaller or larger than k.*/