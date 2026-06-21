/*
problem link - https://leetcode.com/problems/search-a-2d-matrix/description/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m * n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target)
                return true;

            else if (matrix[row][col] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return false;
    }
};


/*
intution - Treat the matrix as one long sorted array. Binary search on the indices, not on the matrix. 
Whenever you need the value at an index, convert it back using:
row = index / number_of_columns
col = index % number_of_columns
*/