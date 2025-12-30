/*
probelm link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count =0;
        ListNode* t=head;
        ListNode* temp=head;
        while(t)
        {
            count++;
            t=t->next;
        }
        int p=count-n+1;
        if(p==1)
        {
            temp = temp->next ;
            head = temp;
        }
        else
        {
            for(int i=0;i<p-2;i++)
            {
                temp = temp->next;
            }
            if(temp->next!=NULL)
            {
                temp->next = temp->next->next;
            }
        }

        return head;
    }
};
