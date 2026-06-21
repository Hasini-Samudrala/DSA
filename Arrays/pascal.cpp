/*Problem link - https://leetcode.com/problems/pascals-triangle/
*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        for(int i = 0; i < numRows; i++) {

            vector<int> row;
            long long val = 1;

            for(int j = 0; j <= i; j++) {
                row.push_back(val);

                val = val * (i - j);
                val = val / (j + 1);
            }

            ans.push_back(row);
        }

        return ans;
    }
};

/*
for normal fimding at a given row and a column we can directly use the formula - nCr 
where n stands for row -1  and r stands for col -1 

but when we are asked to print the whole row then we can do smtg like 
seeing the pattrens like 
here - ans *( row-col) /(col) 
basically when we check teh 5th row for example 
we have this 
1 , 5, 10, 10,5 , 1
so there 
row number is 6 
column number strats from 0 ....5
first element is 1 
second element is 1*(6-1)/1
third element is 5*(6-2)/2
and so on....

*/