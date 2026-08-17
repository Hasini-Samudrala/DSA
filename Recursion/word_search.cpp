/*problem link - https://leetcode.com/problems/word-search/ */

class Solution {
public:
    int rows,cols;

    bool dfs(vector<vector<char>>&board,string &word,int r, int c , int index){
        if(word.length()==index) return true;

        if(r<0 || r>=rows || c<0 || c >= cols || board[r][c]!= word[index]){
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(board,word,r,c+1,index+1) ||
                    dfs(board,word,r,c-1,index+1) ||
                    dfs(board,word,r-1,c,index+1) || 
                    dfs(board,word,r+1,c,index+1);

        board[r][c] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for(int i = 0 ;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};

/*intution -
This is grid-based backtracking (DFS) — a different flavor again from the array/subset problems. Try starting the word 
from every cell in the grid. From each starting cell, explore all 4 directions (up/down/left/right), matching one
 character of word at a time. Mark cells as visited as you go (so the same cell isn't reused), 
and unmark on backtrack so other paths can still use that cell. If you match all characters of word, return true.


Why in-place marking (board[r][c] = '#') instead of a separate visited 2D array: it's simpler and saves O(m×n) extra space, 
since the board itself can temporarily hold the "visited" state (no valid word ever legitimately contains #).
 The critical part is always restoring the original character before returning from that recursive branch —
  otherwise other starting points/paths would incorrectly see cells as permanently blocked.

Why this differs from earlier problems: there's no start index or "pool of candidates" here at all — it's spatial 
adjacency-based backtracking on a 2D grid, where the "next choices" are determined by grid position (4 neighbors) rather 
than array index. The visited-marking + unmarking (mark → recurse → restore) is the core backtracking pattern, same spirit 
as push_back/pop_back in the earlier problems, just applied to grid cells instead of a result vector.

Complexity: O(m × n × 4^L) where L = word length, since from each of the m×n starting cells, DFS branches up to 4 ways at
 each of L steps (in practice much less due to pruning from board boundaries/mismatches and no-revisit constraint).
 */