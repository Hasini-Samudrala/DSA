/*
Problem link - https://leetcode.com/problems/delete-node-in-a-linked-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val ;
        node->next = node->next->next ;
    }
};

//Intution 
/*
so u need to remove the node element 
so u assign node ka value to teh node ka next ka value and 
node ka next as node ka next ka next 

*/