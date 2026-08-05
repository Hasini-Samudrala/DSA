/*problem link - https://leetcode.com/problems/merge-k-sorted-lists/ */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto list:lists){
            while(list!=NULL){
                pq.push(list->val);
                list = list->next;
            }
        }

        ListNode* dummy= new ListNode(0);
        ListNode* curr = dummy;

        while(!pq.empty()){
            curr->next = new ListNode(pq.top());
            pq.pop();
            curr = curr->next;
        }

        return dummy->next;
    }
};

//chumma inserting all elements into the pq and then taking the min everytime 
// not optimal - o(nlogn)


//optimal - o(nlogk)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class compare{
    public:
        bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;

        for(auto list:lists){
            if(list)
             pq.push(list);
        }

        ListNode* dummy= new ListNode(0);
        ListNode* tail = dummy;

        while(!pq.empty()){
           ListNode* curr = pq.top();
            tail->next = curr;
            pq.pop();
            tail = tail->next;

            if(curr->next)
            pq.push(curr->next);
        }

        return dummy->next;
    }
};

/*
make sure u check the implementation - thoda different

Since each linked list is already sorted, only the head node of each list can be the smallest remaining element from that list.
Therefore, the overall smallest element must be among the k head nodes, so we insert only those into the min heap.
After removing the smallest head, the next node in that same list becomes the new smallest candidate from that list, so we insert only that node.
This way, the heap always contains exactly the nodes that are capable of being the next smallest, so we never need to store all N nodes.

*/