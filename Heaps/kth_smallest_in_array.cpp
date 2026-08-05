/* problem link - https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1*/

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>pq;
        for(auto x :arr){
            pq.push(x);
            if(pq.size()>k)
            pq.pop();
        }
        return pq.top();
    }
};

/*
The idea is to maintain a max heap of size k while iterating through the array.
The heap always contains the k smallest elements seen so far. If the heap size exceeds k, 
remove the largest element. At the end, the heap holds the k smallest elements. 
*/

