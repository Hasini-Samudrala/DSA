/* problem link - https://www.geeksforgeeks.org/problems/convert-an-array-to-reduced-form1101/1 */

class Solution {
  public:
    void replaceWithRank(vector<int>& arr) {
        // code here
        vector<int>sortedArr= arr;
        sort(sortedArr.begin(),sortedArr.end());
        unordered_map<int,int>rankMap;
        int rank =0;
        
        for(auto num:sortedArr){
            if(rankMap.find(num)== rankMap.end()){
                rankMap[num]=rank;
                rank++;
            }
        }
        
        vector<int>result;
        for(auto num:arr){
            result.push_back(rankMap[num]);
        }
        
        for(int i=0;i<arr.size();i++){
            arr[i]= result[i];
        }
    }
};

//Make a copy of the array to avoid modifying the original.
// Sort the copied array in ascending order.
// Use a map or dictionary to assign rank starting from 1, skipping duplicates.
// Loop through the original array and replace each element with its rank using the map.


// for gfg version 
class Solution {
  public:
    void replaceWithRank(vector<int>& arr) {
        // code here
        vector<pair<int,int>>temp;
        
        for(int i=0;i<arr.size();i++){
            temp.push_back({arr[i],i});
        }
        sort(temp.begin(),temp.end());
        
        int rank = 0;
        for(int i = 0;i<arr.size();i++){
            arr[temp[i].second]= rank;
            rank++;
        }
    }
};

/*
Suppose

arr = [20, 10, 20]

After sorting:

temp = [(10,1), (20,0), (20,2)]

Now the first loop does:

i (rank)	temp[i]	ans after assignment
0	(10,1)	[-,0,-]
1	(20,0)	[1,0,-]
2	(20,2)	[1,0,2]

*/