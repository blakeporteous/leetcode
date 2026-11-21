class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool word;

    TrieNode() : word(false) {}
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(const string& word, int j, TrieNode* node){
        TrieNode* cur = node;

        for(int i = j; i < (int)word.size(); i++){
            char c = word[i];

            if(c == '.'){
                for(auto& [ch, child] : cur->children){
                    if (dfs(word, i + 1, child)) return true;
                }
                return false;
            } else {
                if(!cur->children.count(c)) return false;
                cur = cur->children[c];
            }
        }
        return cur->word;
    }
            
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;

        for(char c : word){
            if(!cur->children.count(c)){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
