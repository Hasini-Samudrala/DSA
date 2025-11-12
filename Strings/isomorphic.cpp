/*
problem link - https://leetcode.com/problems/isomorphic-strings/description/
*/

//approach-1
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> charS;
        unordered_map<char,int> charT;

        for(int i=0;i<s.length();i++){
            if(charS.find(s[i])==charS.end()){
                charS[s[i]]=i;
            }
            if(charT.find(t[i])==charT.end()){
                charT[t[i]]=i;
            }
            if(charS[s[i]]!=charT[t[i]]){
                return false;
            }
        }
        return true;
    }
};

/*
giving a number to a particular character in a string , like mapping that particuar character to that particuar loop number 
after that in both the maps u check if the number they are corresponding to is same , if yes then true else no false in teh middle 
of the loop 
*/