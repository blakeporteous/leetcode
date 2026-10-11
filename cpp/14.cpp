class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = strs[0];

        if (strs.empty()) {
            return "";
        }

        for(int i=1;i<strs.size();i++){
            while (strs[i].find(prefix) !=0){
                prefix.pop_back();
            }
        }

        return prefix;
    }
};
