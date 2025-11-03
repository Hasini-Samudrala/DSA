/*
Problem Link : https://leetcode.com/problems/rotate-array/
in short - we need to roatte the array by some places to the left and return the array 
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n);
        k %= n;
        for(int i = 0; i < n; i++) {
            result[(i + k) % n] = nums[i];
        }
        nums = result;
    }
};

/*
INTUTION :
first if the size of the array is 5 and we were supposed to rotate by say 6 places this would lead to the originalarray with one place 
moved so we wpuld do that modulus thing k = k%n so that number of places can be reduced in some situtaions 
next we would move a particular element to the (i+k)%n position 
Because if you're rotating right by k, the element at index i moves to (i + k) — but to stay in bounds, we take modulo n.
*/


class Solution{
    public:
    void rotate(vector<int>&nums, int k ){
        int n =  nums.size();
        for(int i=0;i<k;i++){
            int p = nums[0];
            nums[0] = nums[n-1];
            for(int j = nums.size()-1 ; j >1;j--){
                nums[j] = nums[j-1];
            }
            if(n>=2){
            nums[1] = p;}
        }
    }
};

/*normal rotation of teh array , but time complexity it doesnt work */