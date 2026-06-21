/*
probelm link - https://leetcode.com/problems/merge-sorted-array/description/
*/
class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
    int i = m - 1;         // last actual element in arr1
    int j = n - 1;         // last element in arr2
    int k = m + n - 1;     // last index of arr1

    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            arr1[k--] = arr1[i--];
        } else {
            arr1[k--] = arr2[j--];
        }
    }

    // Copy any remaining elements of arr2
    while (j >= 0) {
        arr1[k--] = arr2[j--];
    }
}

};

/*
we are merging without using extra space 
kinda two pointers without any extra array 
*/