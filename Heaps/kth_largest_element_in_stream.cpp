/*problem link - https://leetcode.com/problems/kth-largest-element-in-a-stream/description/ */

class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;

        for(auto x:nums){
            pq.push(x);

            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

 /*
Create a min-heap.
Insert the first k elements from the initial stream into the heap.
For the remaining elements in the initial stream:
        If the element is greater than the smallest in heap, insert it and remove the smallest.
When a new element is added via add()       
        Insert it into the heap.
        If heap size exceeds k, remove the smallest.
Return the top of the heap (kth largest). 
*/