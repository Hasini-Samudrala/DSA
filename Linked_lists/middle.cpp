/*
Problem link - 
https://leetcode.com/problems/middle-of-the-linked-list/description/
*/

class Solution{
    public:
    ListNode* middleelement(ListNode* head)
    {
        ListNode* t =  head ;
        while(head && head->next)
        {
            head = head->next->next;
            t = t->next;
        }
        return t;
    }
};

//Intution 
/*
So we need to return from the middle node 
so here this is fats nd slow pointer method 
in whoch we would move a node with 2x speed and the other with 1x speed so by the time one reaches teh end 
teh other would be at teh middle exactly nd also as teh required one is say that if it is even then we need teh 
second element that also covers in this case 

*/