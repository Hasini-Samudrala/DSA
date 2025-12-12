/*
probelem link -https://leetcode.com/problems/odd-even-linked-list/description/
*/


//code
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = even;

        while( even && even->next){
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};

//intution

/*
The list must be rearranged so that all nodes in odd positions (1st, 3rd, 5th, …) appear first, followed by all nodes in even positions (2nd, 4th, 6th, …), while keeping the original relative order inside both groups.

The key idea is to split the list into two chains as we walk through it:

The odd pointer builds a chain of odd-indexed nodes.

The even pointer builds a chain of even-indexed nodes.

Since the odd and even nodes already appear in alternating order, we can simply “skip” over each other by relinking:

odd → odd → odd…

even → even → even…

We maintain the head of the even chain so that after finishing the rearrangement, we can append the even list at the end of the odd list. This works in a single traversal, doesn't create new nodes, and keeps O(1) extra memory because we only adjust pointers, not values.

Final structure:
odd-list → even-list
*/