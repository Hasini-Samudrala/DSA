/*
problem link - https://leetcode.com/problems/valid-parentheses/description/
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int len = s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='(' || s[i] =='{' || s[i] =='[')
            st.push(s[i]);

            else if(s[i]==')' &&  !st.empty() && st.top()=='(')
            st.pop();

            else if(s[i]==']' &&  !st.empty() && st.top()=='[')
            st.pop();

            else if(s[i]=='}' &&  !st.empty() && st.top()=='{')
            st.pop();

            else
            st.push(s[i]);
        }
        if(st.empty())
        return true;

        else
        return false;
    }
};


// need not traverse the whole string when there is a wring in the middle 
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if (ch == ')' && top != '(') return false;
                if (ch == ']' && top != '[') return false;
                if (ch == '}' && top != '{') return false;
            }
        }
        return st.empty();
    }
};