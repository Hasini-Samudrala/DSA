/*
problem link  -https://leetcode.com/problems/palindrome-linked-list/description/
*/

//code
//approach-1
class Solution{
    public:
    ListNode* cloneList(ListNode* head) {
    if (!head) return nullptr;
    ListNode* newHead = new ListNode(head->val);
    ListNode* p = newHead;
    ListNode* q = head->next;
    while (q) {
        p->next = new ListNode(q->val);
        p = p->next;
        q = q->next;
    }
    return newHead;
}
    ListNode* reverseList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp){
            ListNode* n = temp->next;
            temp->next = prev;
            prev= temp;
            temp = n;
        }
        head = prev;
        return head;
    }
    bool isPalindrome(ListNode* head){
        if(head==NULL) return true;
        if(head->next ==NULL) return true;
        ListNode* copy = cloneList(head);
        ListNode* reverse= reverseList(head);
        while(copy){
            if(copy->val==reverse->val){
                copy = copy->next;
                reverse = reverse->next;
            }
            else
            return false;
        }
        return true;
    }
};


//reverse the whole linked list and compare with the initial list 

//code -2
//approach-2
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Compare the first half and the reversed second half
        ListNode* first = head;
        ListNode* second = prev; // prev is now the head of the reversed second half
        while (second) { // Only need to check second half
            if (first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};

//intution
/*u go till half of the list and then try to reverse the second half and compare it with the first half */