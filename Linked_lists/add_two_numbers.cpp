/*
problem link - https://leetcode.com/problems/add-two-numbers/description/
*/

// code -1 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_dummy = l1;
        ListNode* l2_dummy = l2;

        ListNode* result = new ListNode();
        ListNode* res = result;

        int carry = 0;

        
        while (l1_dummy != NULL && l2_dummy != NULL) {
            int value = l1_dummy->val + l2_dummy->val + carry;
            if(value>=10){
                carry =1;
                value = value-10;
             }
            else{
              carry=0;
             }

            result->next = new ListNode(value);
            result = result->next;

            l1_dummy = l1_dummy->next;
            l2_dummy = l2_dummy->next;
        }

        
        while (l1_dummy != NULL) {
            int value = l1_dummy->val + carry;
            if(value>=10){
                carry =1;
                value = value-10;
             }
            else{
              carry=0;
             }

            result->next = new ListNode(value);
            result = result->next;

            l1_dummy = l1_dummy->next;
        }

        
        while (l2_dummy != NULL) {
            int value = l2_dummy->val + carry;
            if(value>=10){
                carry =1;
                value = value-10;
             }
            else{
              carry=0;
             }

            result->next = new ListNode(value);
            result = result->next;

            l2_dummy = l2_dummy->next;
        }

        
        if (carry == 1) {
            result->next = new ListNode(carry);
        }

        return res->next;
    }
};


/*
here normally i am adding teh two numbers by creating two dummy lists and then accessing through that lists 
now when i get a carry i am adding it to the next value then after the main loop 
there if u have the lists in such a way that the lengths of two lists are not equal then 
we run the loops again sepeartely to see which list is not being done completely and then follow teh same logic 
*/

//code-2

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_dummy = l1;
        ListNode* l2_dummy = l2;

        ListNode* result = new ListNode();
        ListNode* res = result;

        int carry = 0;

        
        while (l1_dummy != NULL && l2_dummy != NULL) {
            int value = l1_dummy->val + l2_dummy->val + carry;
            carry = value / 10;
            value = value % 10;
            
            result->next = new ListNode(value);
            result = result->next;

            l1_dummy = l1_dummy->next;
            l2_dummy = l2_dummy->next;
        }

        
        while (l1_dummy != NULL) {
            int value = l1_dummy->val + carry;
            carry = value / 10;
            value = value % 10;
            

            result->next = new ListNode(value);
            result = result->next;

            l1_dummy = l1_dummy->next;
        }

        
        while (l2_dummy != NULL) {
            int value = l2_dummy->val + carry;
            carry = value / 10;
            value = value % 10;
            

            result->next = new ListNode(value);
            result = result->next;

            l2_dummy = l2_dummy->next;
        }

        
        if (carry == 1) {
            result->next = new ListNode(carry);
        }

        return res->next;
    }
};

/*
it is the same logic but in teh place of if else condition , here we just follow divide by and mod operators for the carry part and teh 
part that is being as value 
this is more optimised than the previous code 
*/