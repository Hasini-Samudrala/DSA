/*
probelm link - https://leetcode.com/problems/largest-odd-number-in-string/description/
*/

//aPPROACH-1
class Solution {
public:
    string largestOddNumber(string num) {
        string final="";
        string even="";

        for(char c:num){
            int k = c-'0';
            if(k%2==1){
                if(even!=""){
                    final += even;
                }
                final +=c;
                even ="";
            }
            else{
                even +=c;
            }
        }
        return final;
    }
};


//intution
/*
so basically the thing is i want to find teh greatest odd number in that string 
so wht i did see 
going through teh string 
when i found an even i put some other string coz if there is an odd number later only then the even i saw till there will be useful
else it woint be useful thats why i sepreted that and started seeing where there is odd number , when i encounter an odd integer then 
i would go back to that so called even string and see if it is not empty , then i add it to teh final string 
and again make that even to be an empty string and collect the next even numbers from teh actual string
*/


//approach-2
class Solution{
    public:
    string largestOddNumber(string num){
        string ans="";
        int n = num.size();
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2) return num.substr(0,i+1);
        }
        return "";
    }
};

//intution
/*
so basically here we are supposed to find the largest but its like see the last number needs to be odd for teh entire string 
to be odd so i started form teh last 
if it is odd , then well nd good , that is my LARGEST ODD STRINIG 
if nit decrease the ocunter by 1 and check again 
this loop continues till teh first digit 
if none of them is odd then it returns an empty string 
*/