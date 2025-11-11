/*
Probelm link - https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
*/

//approach-1
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
         map<int,int> hash;
         for(int i =0;i<arr.size();i++){
             hash[arr[i]]++;
         }
         
         vector<int> nums;
         int k = hash[0];
         int m = hash[1];
         int n = hash[2];
         
         while(k){
             nums.push_back(0);
             k--;
         }
         
         while(m){
             nums.push_back(1);
             m--;
         }
         
         while(n){
             nums.push_back(2);
             n--;
         }
         
         arr = nums;
    }
};

//intution - chuma only

//approach -2

class Solution{
    public:
    void sort012(vector<int>& arr){
        int low=0;
        int mid=0;
        int high = arr.size()-1;

        while(mid<=high)
        {
            if(arr[mid]==0){
                swap(arr[low++],arr[mid++]);
            }

            else if(arr[mid]==1){
                mid++;
            }

            else{
                swap(arr[mid],arr[high--]);
            }
        }
    }
};

//DNF algorithm 