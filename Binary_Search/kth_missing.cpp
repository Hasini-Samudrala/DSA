/*
problem link - https://leetcode.com/problems/kth-missing-positive-number/
*/

//approach-1
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int l = 0 ;
        int r= nums.size()-1;
        int counter =0;
        int m=0;
        while(l<=r){
            m = (l+r)/2;
            int miss = nums[m]-(m+1);
            if(miss<k){
                l=m+1;
            }
            else{
                r=m-1;
            }
            }
            return k+l;
        }   
    };



//intuition
/*
In a sorted array, at index m the number of missing positive integers before nums[m]
 is nums[m] − (m+1) because the values should have been 1,2,...,m+1 if nothing were missing. 
 This function increases with m, so we binary-search for the first index l where 
 missing ≥ k. At that index, exactly l natural numbers (1..l) have appeared in the array, 
 and to have k missing numbers, the total natural numbers considered must be k + l. 
 Therefore, the k-th missing positive integer is simply k + l
 (and if l goes past the array, it becomes k + n).*/