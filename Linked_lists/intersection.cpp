/*
problem link - https://leetcode.com/problems/intersection-of-two-linked-lists/description/
*/

//code
//approach-1
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* a = headA;
        ListNode* b = headB;
        while(a){
            a= a->next;
            lenA++;
        }
        while(b){
            b = b->next;
            lenB++;
        }

        a = headA;
        b= headB;
        if(lenA > lenB){
            for(int i=0;i<lenA-lenB;i++) a = a->next;
        }
        else{
            for(int i=0;i<lenB-lenA;i++) b = b->next;
        }

        while(a&&b){
            if(a==b) return b;
            a=a->next;
            b=b->next;
        }
        return nullptr;
    }
};

//u would basically make the two linked lsits of same size and then traverse till u reach the common node 

//approach - 2
class Solution{
    public:
    ListNode* getIntersectionNode(ListNode* headA , ListNode* headB){
        ListNode* a = headA;
        ListNode* b = headB;

        while(a!=b){
            a= (a==nullptr)?headB:a->next;
            b=(b==nullptr)?headA:b->next;
        }
        return a;
    }
};