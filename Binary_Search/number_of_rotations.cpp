/*problem link - https://www.geeksforgeeks.org/problems/rotation4723/1 */

class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        // Code Here
        int low = 0;
        int high = nums.size()-1;
        int ans = 0;
        while(low<=high){
            if(nums[low]<nums[high])
            return ans;
            
            int mid = (low+high)/2;
            if(nums[low]<=nums[mid]){
                ans = mid+1;;
                low  = mid+1;
            }
            else{
                high =  mid;
                ans = mid;
            }
        }
        return ans-1;
    }
};


/**/