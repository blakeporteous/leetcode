class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string res = "";
        for(const string& s : strs){
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> res;
        int i = 0;

        while(i < str.size()){
            int j = i;
            while(str[j] != '#'){
                j++;
            }
            int length = stoi(str.substr(i, j-i));
            res.push_back(str.substr(j + 1, length));
            i = j + 1 + length;
        }

        return res;


    }
};
