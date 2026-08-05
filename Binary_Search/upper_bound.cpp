/*problem link - https://www.geeksforgeeks.org/problems/implement-upper-bound/1*/

class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>target){
                ans = mid;
                high = mid-1;
            }
            else
            low = mid+1;
        }
        return ans;
    }
};


/*
Find the first element that is strictly greater than the target (> target). 
Whenever arr[mid] > target, store the answer and search left for an earlier occurrence.
*/