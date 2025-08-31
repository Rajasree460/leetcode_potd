class Solution {
    boolean[][] visited = new boolean[10][60]; // 9 rows and values are till 58, so round figure 60
    boolean[][] rows = new boolean[10][60];
    boolean[][] cols = new boolean[10][60];
    int dots = 0;
    public void solveSudoku(char[][] board) {
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(board[r][c] != '.') {

                    rows[r][board[r][c]] = true;
                    cols[c][board[r][c]] = true;
                    
                    int box = (r / 3) * 3 + (c / 3) + 1;
                    visited[box][board[r][c]] = true;
                }
                else dots++;
            }
        }
        backtrack(board);
    }
    boolean backtrack(char[][] board) {
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(board[r][c] != '.') continue;
                
                for(char val = '1'; val <= '9'; val++) {
                    if(valid(board, r, c, val)) {
                        board[r][c] = val;
                        rows[r][val] = true;
                        cols[c][val] = true;
                        int box = (r / 3) * 3 + (c / 3) + 1;
                        visited[box][val] = true;
                        dots--;
                        if(dots == 0) return true;

                        if(backtrack(board)) return true;

                        visited[box][val] = false;
                        rows[r][val] = false;
                        cols[c][val] = false;
                        board[r][c] = '.';
                        dots++;
                    }
                }
                return false;
            }
        }
        return true; // we can also return false here, doesn't matter
    }
    boolean valid(char[][] board, int row, int col, char val) {
        if(rows[row][val] == true) return false;
        if(cols[col][val] == true) return false;
        int box = (row / 3) * 3 + (col / 3) + 1;
        if(visited[box][val] == true) return false;
        return true;
    }
}
