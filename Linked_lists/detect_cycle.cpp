/*
probelm link - https://leetcode.com/problems/linked-list-cycle/description/
*/

//approach
class Solution{
    public:
    bool hasCycle(ListNode* head){
        ListNode* t1 = head;
        ListNode* t2= head;
        while(t2){
            t2 = t2->next;
            if(t1==t2) return true;
            t1 = t1->next;
            if(t2) t2 = t2->next;
        }
        return false;
    }
};

//floyd's cycle algorithm given in the book 
