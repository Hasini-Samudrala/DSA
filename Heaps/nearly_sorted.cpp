/*problem link - https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1 */

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        // sort(arr.begin(),arr.end());
        priority_queue<int,vector<int>,greater<int>>minHeap;
        
        for(int i =0;i<=k;i++){
            minHeap.push(arr[i]);
        }
        vector<int>result;
        
        for(int i=k+1;i<arr.size();i++){
            result.push_back(minHeap.top());
            minHeap.pop();
            minHeap.push(arr[i]);
        }
        
        while(!minHeap.empty()){
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        
        for(int i =0;i<arr.size();i++){
            arr[i]= result[i];
        }
    }
};

//since every element is atmost k distance from its exact position in the sorted array 
// we can tell that the smallest element is among the first k+1 elements 
// so first we go insert the k+1 elements of the array into the pq
// then the first element in the pq is saying that it is the smallest element in the whole array 
//later we start inserting element one by one and the top element everytime is the next smallest element 
// after inserting all the elements of the array we go and empty the pq and insert into our result