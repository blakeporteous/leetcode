class Solution {
private:
    vector<vector<char>> board;
    string word;
    int rows, cols;

    bool dfs(int r, int c, int i){
        if(i == word.size()) return true;

        if (r < 0 || c < 0 || r >= rows || c >= cols || word[i] != board[r][c]) return false;

        char temp = board[r][c];
        board[r][c] = '#';
        bool res = (dfs(r + 1, c, i + 1)) ||
            (dfs(r - 1, c, i + 1)) ||
            (dfs(r, c + 1, i + 1)) ||
            (dfs(r, c - 1, i + 1));

        board[r][c] = temp;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        rows = board.size(); 
        cols = board[0].size();

        for(int r =0; r < rows; r++) {
            for(int c = 0; c < cols; c++){
                if (dfs(r, c, 0)) return true;
            }
        }

        return false;
    }
};
