class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;

    TrieNode() { isWord = false; }

    void addWord(const string& word){
        TrieNode* cur = this;
        for (char c : word) {
            if(!cur->children.count(c)){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
};

class Solution {
private:

    vector<vector<char>> board;
    int rows, cols;
    set<string> res;

    void dfs(int r, int c, TrieNode* node, string word){
        if(r < 0 || c < 0 || r >= rows || c >= cols|| !node->children.count(board[r][c])){
            return;
        }
        char ch = board[r][c];
        node = node->children[ch];
        word += ch;

        if(node->isWord){
            res.insert(word);
            node->isWord = false;
        }

        board[r][c] = '#';
        dfs(r + 1, c, node, word);
        dfs(r - 1, c, node, word);
        dfs(r, c + 1, node, word);
        dfs(r, c - 1, node, word);
        board[r][c] = ch;

        if(node->children.empty() && !node->isWord){
            node->children.erase(ch);
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(const string& word : words) {
            root->addWord(word);
        }

        this->board = board;
        rows = board.size();
        cols = board[0].size();

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                dfs(r, c, root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
