/*
Problem link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
*/

class Solution {
public:
    int f(int n,vector<int> &nums,int target)
    {
        int l=0;
        int r=nums.size()-1;
        int result=-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(nums[m]==target)
            {
                result=m;
                if(n) r=m-1;
                else l=m+1;
            }

            else if(nums[m]<target) l=m+1;

            else r=m-1;
        }

        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

    int s=f(1,nums,target);
    int e=f(0,nums,target);

    vector<int> result;
    result.push_back(s);
    result.push_back(e);

    return result;
    }
};


//Intution
/*
so basically we need to find a element in sorted array so we do binary search
but we have replicated elements in the array 
so when we try to find the first position we would make r as m-1
and when u r finding teh last position of the element then we make l as m+1
and for this we would mainatin an varaible say n and call it with 1 and 0 according to teh situation 
*/


class Solution {
public:
    int firstOccurrence(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int first = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            first = mid;
            high = mid - 1;      // Search on the left
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return first;
}

    int lastOccurrence(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            last = mid;
            low = mid + 1;       // Search on the right
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return last;
}
    vector<int> searchRange(vector<int>& nums, int target) {
      
    int first = firstOccurrence(nums, target);
    if(first==-1) return {-1,-1};
    int last = lastOccurrence(nums, target);

    return {first, last};
}
    
};


//direct logic 