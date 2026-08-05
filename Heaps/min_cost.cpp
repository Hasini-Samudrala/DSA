/*problem link - https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1*/

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x:arr){
            pq.push(x);
        }
        int cost =0;
        while(pq.size()>1){
            int first = pq.top();
            pq.pop();
            
            int second =pq.top();
            pq.pop();
            
            int sum = first+second;
            cost+=sum;
            pq.push(sum);
        }
        return cost;
    }
};

/*
Connecting two ropes creates a new rope that will be used in future connections.
To minimize repeated contribution to the total cost, always connect the two smallest ropes first.
Use a min heap to efficiently retrieve the two smallest ropes at every step.
After merging, add the new rope back into the heap until only one rope remains
*/