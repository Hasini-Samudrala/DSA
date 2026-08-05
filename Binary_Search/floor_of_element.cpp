/*problem link - https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1 */

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans=-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]<=x){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};


/*
Find the largest element that is smaller than or equal to the target (≤ target). 
Whenever arr[mid] <= target, store it as a potential answer and search right to find a larger valid floor.
*/