/* problem link - https://leetcode.com/problems/kth-largest-element-in-an-array/ */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x:nums){
            pq.push(x);
            if(pq.size()>k)
            pq.pop();
        }
        return pq.top();
    }
};

/* we are adding the elements to a min heap and then everytime the size goes beyond k , we try to remove the top element..
Maintain a min heap of size k to store the k largest elements seen so far.
Insert each element into the heap. If the heap size exceeds k, remove the smallest element.
This ensures only the largest k elements remain in the heap.
The top of the min heap is the kth largest element, since it is the smallest among those k largest elements.
*/