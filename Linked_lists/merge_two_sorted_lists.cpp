/*problem link - https://leetcode.com/problems/merge-two-sorted-lists/description/*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = new ListNode(0);
        ListNode* res= temp;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                temp ->next = list1;
                list1= list1->next;
            }
            else
            {
                temp ->next = list2 ;
                list2= list2->next ;
            }
            temp = temp->next ;
        }
        if(list1) temp->next = list1;
        if(list2) temp->next = list2;
        return res->next ;
    }
};

/*Use a dummy head node to avoid messy edge-case handling for "which node starts the result." Walk both lists with two pointers,
 always attaching the smaller current node to your result, and advancing that list's pointer. Once one list runs out, 
just attach whatever's left of the other — since both are already sorted, no more comparison is needed.*/