/*problem link - https://leetcode.com/problems/median-of-two-sorted-arrays/ */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
        return findMedianSortedArrays(nums2,nums1);

        int n = nums1.size();
        int m = nums2.size();

        int low =0;
        int high  = n;
        while(low<=high){
            int partitionA = (low+high)/2;
            int partitionB = (n+m+1)/2 - partitionA;

            int leftA = (partitionA==0) ? INT_MIN : nums1[partitionA-1];
            int rightA = (partitionA ==n ) ? INT_MAX: nums1[partitionA];

            int leftB = (partitionB==0) ? INT_MIN:nums2[partitionB-1];
            int rightB = (partitionB==m)?INT_MAX: nums2[partitionB];

            if(leftA<=rightB && leftB<=rightA){
                if((n+m)%2 ==0){
                    return (max(leftA,leftB)+min(rightA,rightB))/2.0;
                }
                else
                return max(leftA,leftB);
            }

            else if(leftA>rightB)
            high = partitionA-1;

            else 
            low = partitionA+1;
        }
        return 0;
    }
};

/*The golden rule ⭐
Largest element on the LEFT
        ≤
Smallest element on the RIGHT

Since the arrays are individually sorted:

The largest candidate from A's left half is leftA.
The largest candidate from B's left half is leftB.
The smallest candidate from A's right half is rightA.
The smallest candidate from B's right half is rightB.


The easiest way to remember

Imagine the cut.

A

...... leftA | rightA ......
B

...... leftB | rightB ......

The only two places where the order can break are:

leftA > rightB

or

leftB > rightA

Every other element is already sorted inside its own half.

So we only check the two elements touching the partition

*/