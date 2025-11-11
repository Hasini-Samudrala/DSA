/*
question description - https://www.geeksforgeeks.org/dsa/move-negative-numbers-beginning-positive-end-constant-extra-space/
*/

//approach- 1

class Solution{
    public:
    vector<int> move(vector<int> &arr){
        int j=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
        return arr;
    }
};

//approach -2 
// this is two pointer method

class Solution{
    public:
    vector<int> move(vector<int>& arr){
        int left =0;
        int right = arr.size();
        while(left<right){
            while(left<right && arr[left]<0){
                left++;
            }

            while(right>left && arr[right]>0){
                right--;
            }

            while(right>left)
            {
                swap(arr[left],arr[right]);
                left++;
                right--;
            }

        }
        return arr;
    }
};

