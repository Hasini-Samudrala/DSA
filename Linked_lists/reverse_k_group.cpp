/*
probelm link - https://leetcode.com/problems/reverse-nodes-in-k-group/description/
*/
class Solution {
public:

    void reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp!= NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
    }

    ListNode* kthNode(ListNode* temp,int k){
        k = k-1;
        while(temp != NULL && k>0){
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode* kth = kthNode(temp,k);
            if(kth==NULL){
                if(prev) prev->next = temp;
                break;
            }
            ListNode* ne = kth->next;
            kth->next = NULL;
            reverse(temp);
            if(temp == head){
                head = kth;
            }
            else{
                prev->next = kth;
            }
            prev = temp;
            temp = ne;
        }
        return head;
    }
};

// from strivers