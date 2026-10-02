class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_set<char>> rows(9);
        std::vector<std::unordered_set<char>> cols(9);
        std::vector<std::vector<std::unordered_set<char>>> sqrs(3, std::vector<std::unordered_set<char>>(3));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                if (rows[i].contains(board[i][j]) || cols[j].contains(board[i][j]) || sqrs[i / 3][j / 3].contains(board[i][j]))
                {
                    return false;
                }
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                sqrs[i / 3][j / 3].insert(board[i][j]);
            }
        }
        return true;
    }
};
