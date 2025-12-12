/*
problem link -https://leetcode.com/problems/linked-list-cycle-ii/description/
*/

//code
class Solution{
    public:
    ListNode* detectCycle(ListNode* head){
        ListNode* t1 = head;
        ListNode* t2 = head;
        while(t2 && t2->next){
            t2= t2->next->next;
            t1 = t1->next;
            if(t1==t2){
                t2= head;
                while(t1!=t2){
                    t1= t1->next;
                    t2 = t2->next;
                }
                return t2;
            }
        }
        return nullptr;
    }
};

//intution
/*1.find whether the cycle is present or not
2.make those pointers to be in the cycle
3.after this we should make one of the pointers as head and again make n=both pointers go at a speed of 1 
4.at any point again these both pointers meet and that is the strating point of the loop 
*/