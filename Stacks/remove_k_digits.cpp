/* problem link - https://leetcode.com/problems/remove-k-digits/description/*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;
        
        int n= num.size();
       
        for (int i=0; i<n ; i++){
           while(!s.empty() && k>0 && (s.top()-'0') > (num[i]-'0')){
            s.pop();
            k--;
           }
           s.push(num[i]);
        }
        while(k>0 && s.size()>0){
            s.pop();
            k--;
        }

        if(s.empty()) return "0";
        string ans ="";
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        while(ans.size() && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans.size()==0) return "0";
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};