class Solution {
public:

    bool isSafe(vector<vector<char>> &board, char value, int row, int col)
    {
        int size = board[0].size();
        for (int i = 0; i < size; i++)
        {
            // check row
            if (board[row][i] == value)
                return false;
            // check column
            if (board[i][col] == value)
                return false;
            // check 3 * 3 box
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == value)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        int size = board[0].size();
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char value = '1'; value <= '9'; value++)
                    {
                        // check conditions
                        if(isSafe(board, value, i, j))
                        {
                            // insert value
                            board[i][j] = value;

                            // recursive call
                            bool nextSolution = solve(board);
                            if(nextSolution)
                            {
                                return true;
                            }

                            // backtrack
                            board[i][j] = '.';
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