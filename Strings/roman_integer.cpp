/*
Problem link - https://leetcode.com/problems/roman-to-integer/description/
*/

//approach -1

class Solution{
    public:
    int romanToInt(string s){
        int res = 0;
        unordered_map<char,int> roman{
            {'I', 1};
            {'V',5};
            {'X',10};
            {'L',50};
            {'C',100};
            {'D',500};
            {'M',1000};
        };

        for(int i=0;i<s.length();i++){
            if(roman[s[i]]<roman[s[i+1]]){
                res -= roman[s[i]];
            }

            else 
            res += roman[s[i]];
        }

        return res;
    }
};

//intution 
/*
we know that when there is XV then we add 10+5 
but when we write IX then it is 10-1 
so basically when the lower ones come first then we need to subtrct that value from teh whoel 
but when it comes after the bigger one then we add that to teh whole result 
*/