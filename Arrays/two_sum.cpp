/*
Probelm link --https://leetcode.com/problems/two-sum/description/

in short - like we need to find teh indices of those two numbers whose sum would be equal to target 
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

       unordered_map<int,int>hashmap;
       for(int i=0;i<nums.size();i++)
       {
        int num = nums[i];
        if(hashmap.find(target-num)!=hashmap.end())
        return {hashmap[target-num],i};
        else
        hashmap[nums[i]]=i;
       } 
       return {};
    }
};

//Intution 
/*
we could have solved by taking two loops but then as time complexity matters we could like to take a different approach 
so here we declared a hash map in which we would like to store the indices of a particular number say num 
then we would use the find operator to find if there is a number called num later in the hash map like in teh next iteration 

*/