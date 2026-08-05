/* problem link - https://takeuforward.org/data-structure/check-if-an-array-represents-a-min-heap*/

class Solution{
    public:
    bool isMinHeap(vector<int>&nums){
        int n = nums.size();
        for(int i = 0 ;i<=(n/2)-1;i++){
            int left = (2*i)-1;
            if(left <n && nums[i]>nums[left])
            return false;

            int right = (2*i)+1;
            if(right<n && nums[i]>nums[right])
            return false;
        }
        return true;
    }
};

// so basically checking if the array is min heap return true else false
// the leaf nodes can not violate the heap property and the leaf nodes satrt from n/2 th index 
// so we need to check the non leaf nodes which are till n/2 -1 th index 
//so for every non leaf element, we need to check its left and right child , if they are following the heap property 
// anywhere it is violating return false , if the loop ends fine then return true 