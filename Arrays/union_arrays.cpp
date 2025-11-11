/*
Probelem link - https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1
*/

//approach - 1
class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int>s;
        for(int x:a) s.insert(x);
        for(int x:b) s.insert(x);
        
        vector<int> ans(s.begin(),s.end());
        return ans;
    }
};