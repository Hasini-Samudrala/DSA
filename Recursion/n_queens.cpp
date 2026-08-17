/*problem link - https://leetcode.com/problems/n-queens/*/

class Solution {
public:
vector<vector<string>>result;
        vector<string>board;
        unordered_set<int>cols,diag1,diag2;

    void backtrack(int row, int n ){
        if(row ==n){
            result.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(cols.count(col)||diag1.count(row-col)||diag2.count(row+col))
            continue;

            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(row-col);
            diag2.insert(row+col);

            backtrack(row+1,n);

            board[row][col] ='.';
            cols.erase(col);
            diag1.erase(row-col);
            diag2.erase(row+col);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n,string(n,'.'))    ;
        backtrack(0,n);
        return result;
    }
};

/*intution - 
The problem in plain words

You have an n x n chessboard. You need to place n queens on it so that no queen can attack another.
 A queen attacks anything in its row, its column, or along either diagonal. You need to find every possible way to do this.

Step 1: The key realization that simplifies everything

Since there are n queens and n rows, and no two queens can share a row (they'd attack each other) — 
every single row must have exactly one queen, no more, no less.

This is huge, because instead of thinking "where do I place all n queens on this big grid," you can think
 row by row: "Row 0 needs one queen. Where? Row 1 needs one queen. Where? ..." and so on down to the last row.

So the whole problem becomes: go through rows 0, 1, 2, ..., n-1 one at a time, and for each row, decide 
which column gets the queen.

Step 2: How do you pick the column for each row?

For row r, you try column 0, then column 1, then column 2, etc. For each column you ask: "if I put a queen here,
 does it attack any queen I've already placed in an earlier row?"

A queen at (r, c) attacks:

Same column as any earlier queen → c matches a used column
Same diagonal (↘ direction) as any earlier queen
Same diagonal (↙ direction) as any earlier queen

(You don't need to check "same row" — since you place exactly one queen per row, that can never conflict.)

If none of these three things are true, it's safe — place the queen there and move to the next row.
 If it IS attacked, just try the next column instead.

Step 3: The clever diagonal trick (this is the part that confuses people)

How do you quickly check "is this diagonal already used"? You could loop and check manually, but there's a neat shortcut.

Picture a cell (row, col). As you move diagonally ↘ (down-right), both row and col increase by 1 each step.
 So row - col stays exactly the same for every cell on that diagonal. That means: all cells sharing the same 
 value of row - col lie on the same ↘ diagonal.

Similarly, moving diagonally ↙ (down-left), row increases but col decreases — so row + col stays constant. 
All cells sharing the same row + col lie on the same ↙ diagonal.

So instead of scanning the board, you just keep 3 simple sets:

cols → which columns already have a queen
diag1 → which row - col values are already "occupied" by a queen
diag2 → which row + col values are already "occupied" by a queen

Checking safety becomes instant: just check if col, row-col, or row+col is already in one of these sets.

Step 4: The "try, then undo" part (backtracking)

You go row by row, and for each row, try each column in order:

If it's safe → place the queen (add col/diag1/diag2 to your sets, mark the board), then recurse to the next row 
and let it try to solve the rest of the board.
Whatever happens in that recursive call, once it returns, you remove the queen again (undo — erase from the sets,
 clear the board cell) before trying the next column in the current row.

Why undo? Because you're exploring all possibilities, not just one. If you tried column 0 in row 0 and eventually 
explored every combination stemming from that choice, you now need to reset row 0 back to empty and try column 1 in 
row 0 instead — a completely fresh branch.

This "place → try to build on it → undo → try something else" pattern is exactly what "backtracking" means. It's 
like walking down a path in a maze, and if that path leads nowhere useful, walking back to the fork and trying a 
different direction — but here every dead end AND every success gets explored, since we want all solutions, not just one.

Step 5: When do you know you found a full solution?

When you successfully place a queen in row n-1 (the last row) without conflict, and there's no "row n" left to
 process — that means row == n in the code — every row from 0 to n-1 has a validly placed queen. That configuration is 
 one complete, valid solution, so you save a copy of the board into your results list.

Then the recursion naturally unwinds back up, undoing queens and trying other columns, to discover other valid
 full solutions too.*/