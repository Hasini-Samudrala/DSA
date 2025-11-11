/*
Probelm link - https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
*/

//approach - 1
// simple but not optimal 
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};


//approach -2

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
     priority_queue<int>pq;
    for(auto it:arr){
        pq.push(it);
        if(pq.size()>k) pq.pop();
    }
    return pq.top();
    }
};