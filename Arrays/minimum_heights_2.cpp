/*
probelm link - https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1
*/

//approach 
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        sort(arr.begin(),arr.end());
        int ans = arr[n-1]-arr[0];
        
        if(arr[n-1]-k<0)
        return ans;
        
        for(int i =1;i<n;i++){
            
            if(arr[i]-k>0) continue;
            
            int high = max(arr[i-1]+k,arr[n-1]-k);
            int low = min(arr[0]+k,arr[i]-k);
            ans = min(ans , high-low);
        }
        return ans;
    }
};


//intution 
// If reducing the largest element makes it negative, then any reduction will
    // make some element negative (since largest goes negative -> others also).
    // So we cannot choose any split that decreases any element; the only valid
    // operation that keeps all >= 0 is to increase everything by k, which
    // preserves the difference arr.back()-arr.front(). Return that.
      // If arr[i] - k < 0, then the first element in the "decrease by k" group
        // would become negative -> invalid split. Skip it.

