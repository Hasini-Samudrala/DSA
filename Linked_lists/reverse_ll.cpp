/*
probelm link - https://leetcode.com/problems/reverse-linked-list/description/
*/

//appraoch-1
//iterative
class Solution{
    public:
    ListNode* reverseList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp){
            ListNode* n = temp->next;
            temp->next = prev;
            prev = temp;
            temp = n;
        }
        head = prev;
        return head;
    }
};

//intution 
//check the notes
