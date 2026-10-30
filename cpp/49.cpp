class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> groups;

        for(int i=0; i<strs.size();i++){
            vector<int> count(26, 0);

            for(int j=0; j<strs[i].length() ;j++){
                count[strs[i][j] - 'a'] += 1;
            }

            string key;
            for(int c : count) key += to_string(c) + "#";

            groups[key].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for(auto& [key, words] : groups) result.push_back(words);
        return result;
    }
};
