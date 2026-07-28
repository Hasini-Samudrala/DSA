class Solution{
    public:
    vector<vector<int>>ans;

    void solve(int i.vector<int>&nums,vector<int>&temp){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,temp);

        temp.pop_back();
        solve(i+1,nums.temp);
    }

    vector<vector<int>> subsets(vector<int>&nums){
        vector<int>temp;
        solve(0,nums,temp);
        return ans;
    }
};

/*
this problem is using teh recursion typa method like we go down t=one path and then backtrack in teh same path and go to the
other path
            []
          ↙     ↘
       [1]       []
      ↙   ↘     ↙   ↘
  [1,2]  [1]  [2]   []
   ↙  ↘   ↙ ↘  ↙ ↘   ↙ ↘
[1,2,3][1,2][1,3][1][2,3][2][3][]

Now match arrows (VERY IMPORTANT)
👉 Flow for ONE path (leftmost)
[] 
 ↓ (take 1)
[1]
 ↓ (take 2)
[1,2]
 ↓ (take 3)
[1,2,3] ✅ PUSH
 ↑ (return)
 ↓ (don’t take 3)
[1,2] ✅ PUSH
 ↑ (return to [1])


🔁 Then continue (your curved arrows)
[1]
 ↓ (don’t take 2)
[1]
 ↓ (take 3)
[1,3] ✅ PUSH
 ↑
 ↓ (don’t take 3)
[1] ✅ PUSH
 ↑ (back to [])


 
🔁 Right side (same pattern)
[]
 ↓ (don’t take 1)
[]
 ↓ (take 2)
[2]
 ↓ (take 3)
[2,3] ✅
 ↓ (don’t take 3)
[2] ✅
 ↓ (don’t take 2)
[]
 ↓ (take 3)
[3] ✅
 ↓ (don’t take 3)
[] ✅*/
