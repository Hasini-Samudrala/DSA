/*
Probelm link - https://leetcode.com/problems/reverse-words-in-a-string/
*/

//Approach 
class Solution {
public:
    string reverseWords(string s) {
        vector<string>ans;
        string cnt="";

        for(char c:s){
            if(c!=' ')
            {
                cnt += c;
            }
            else{
                if(cnt!="")ans.push_back(cnt);
                cnt ="";
            }
        }

        if(cnt!="")ans.push_back(cnt);

        string final="";
        int k= ans.size();
        for(int i=k-1;i>=0;i--)
        {
            final += ans[i];
            if(i!=0)final += " ";
        }

        return final;
    }
};

//intution

/*
chumma only like how we do remaining 
genearilised aff
*/