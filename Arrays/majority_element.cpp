//Problem link 
// https://leetcode.com/problems/majority-element/description/

//Approach -1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return nums[n/2];
    }
};

//Intution 
/*
We know that there exists an element which is repeated more than n/2 times 
so basically teh element at n/2 has to be that element when the array is sorted and thats wht we did
but this takes O(nlogn) time coz of sorting of teh array 
*/

//Approach -2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> hash;
        int res = 0;
        int maj = 0;
        for (int n :nums)
        {
            hash[n] = 1+hash[n];
            if(hash[n]>maj)
            {
                res = n;
                maj = hash[n];
            }
        }

        return res;
    }
};

//Intution 
/*
as the prev apporach takes O(nlogn) time , other optimised approach 
so here we are maintaining a map 
initially everthing would be zero as soon as we see a element then we increment taht hash value and then 
we try to comapre it with teh majority seen so far 
and try to store that element which we are actually talking ant in teh res variable and teh number of times it repeated in the 
maj variable

*/