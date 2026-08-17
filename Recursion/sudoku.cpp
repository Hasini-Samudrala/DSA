/*problem link - https://leetcode.com/problems/sudoku-solver/ */

class Solution {
public:

    bool isValid(vector<vector<char>>&board, int r, int c, int digit){
        for(int i =0;i<9;i++){
            if(board[r][i]==digit) return false;

            if(board[i][c]==digit) return false;

            int boxRow = 3*(r/3) + i/3;
            int boxCol = 3*(c/3) +i%3;

            if(board[boxRow][boxCol]==digit) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>&board){
        for(int row =0;row<9;row++){
            for(int col = 0 ;col<9;col++){
                if(board[row][col]=='.'){
                    for(char digit='1';digit<='9';digit++){
                        if(isValid(board,row,col,digit)){
                            board[row][col]=digit;

                            if(solve(board)) return true;

                            board[row][col]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

/*intution - 
Think of solving Sudoku like filling in a maze where you're allowed to guess — and if a guess turns out wrong later, you erase it and try something else.

Step by step:

Find the first empty cell (marked .) by scanning the board top to bottom, left to right.
Try putting a number 1-9 in it. Before actually placing it, check: "does this number already exist in this row? this column? this 3×3 box?" If yes to any of those, that number's not allowed here — skip to the next number.
If a number is allowed, place it and move on to solve the rest of the board (call the same function again for the next empty cell).
Two things can happen next:
The rest of the board gets solved successfully → great, you're done, stop.
The rest of the board gets stuck somewhere down the line (no valid number fits some later cell) → that means your earlier guess was wrong. Erase it (put the . back) and try the next number (2, then 3, then 4...) in that same cell.
If none of the 9 numbers work for a cell, that means an even earlier guess was bad — so you go back further and change that one instead. This "going back and undoing" is called backtracking.
You're fully done when you scan the whole board and find no more . cells left — every cell has a valid number.
 
Simple analogy: It's like trying to solve a maze by walking forward, and every time you hit a dead end, you walk back to the last fork in the road and try a different path instead. Eventually, since Sudoku puzzles are guaranteed to have exactly one solution, this trial-and-error process is guaranteed to find it.

Why it's not actually slow in practice: Even though in theory you could try tons of combinations, the "is this number allowed here?" check eliminates most bad guesses almost instantly — so real Sudoku boards solve in a fraction of a second even though the code is "just" trial and error with undo.*/