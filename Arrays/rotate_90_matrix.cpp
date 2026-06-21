/*
problem link - https://leetcode.com/problems/rotate-image/description/
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
       for(int row = 0;row<matrix.size();row++){
        for(int col = row ;col<matrix[0].size();col++){
            swap(matrix[row][col],matrix[col][row]);
        }
        for(int s=0;s<matrix[0].size()/2;s++){
            swap(matrix[row][s],matrix[row][n-s-1]);
        }
    }
    }
};

/*intution - u first find the transpose of teh array and then swap to get the actual 90 rotated matrix */