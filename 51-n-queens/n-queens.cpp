class Solution {
public:

    // declare unordered map
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperLeftDiagonalCheck;
    unordered_map<int, bool> lowerLeftDiagonalCheck;

    void storeSolution(vector<vector<char>> &board, int n, vector<vector<string>> &ans)
    {
        vector<string> temp;
        for(int i = 0; i < n; i++)
        {
            string output = "";
            for(int j = 0; j < n; j++)
            {
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
        
    }

    bool isSafe(vector<vector<char>> &board, int n, int row, int col)
    {
        if (rowCheck[row] == true)
        {
            return false;
        }
        if (upperLeftDiagonalCheck[n - 1 + col - row] == true)
        {
            return false;
        }
        if (lowerLeftDiagonalCheck[row + col] == true)
        {
            return false;
        }
        return true;
    }

    void solve(vector<vector<char>> &board, int n, int col, vector<vector<string>> &ans)
    {
        // base case
        if(col >= n)
        {
            storeSolution(board, n, ans);
            return;
        }

        // recursive call
        for(int row = 0; row < n; row++)
        {
            if(isSafe(board, n, row, col))
            {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upperLeftDiagonalCheck[n - 1 + col - row] = true;
                lowerLeftDiagonalCheck[row + col] = true;
                solve(board, n, col + 1, ans);
                rowCheck[row] = false;
                upperLeftDiagonalCheck[n - 1 + col - row] = false;
                lowerLeftDiagonalCheck[row + col] = false;
                board[row][col] = '.';
            }
        }
    }

     vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        int col = 0;
        vector<vector<string>> ans;
        solve(board, n, col, ans);
        return ans;
    }
};