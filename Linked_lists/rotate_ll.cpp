/*
problem link - https://leetcode.com/problems/rotate-list/description/
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head; // Edge case

        //for th elength of the list 
        ListNode* temp = head;
        int len = 1;
        while (temp->next) {
            temp = temp->next;
            len++;
        }

        // for large values of  k 
        k = k % len;
        if (k == 0) return head; // No rotation needed

        // Step 3: Find the new tail will be the last node now len - k - 1 th node
        temp->next = head; // Connect last node to head to make circular list
        int stepsToNewTail = len - k;
        temp = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            temp = temp->next;
        }

        // make the cycle normal , breaking it
        ListNode* newHead = temp->next;
        temp->next = NULL; // Break the cycle

        return newHead;
    }
};

// u make it as a circular list and then try to break where u need 
