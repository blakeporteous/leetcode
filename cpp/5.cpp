class Solution {
private:
    int expand(const string& s, int l, int r){
        int c = 0;

        while(l >= 0 && r < (int)s.size() && s[l] == s[r]){
            c = r - l + 1;
            l--;
            r++;
        }

        return c;
    }
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 0;

        for(int i = 0; i < (int)s.size(); i++){
            //odd
            int len1 = expand(s, i, i);
            // even
            int len2 = expand(s, i, i + 1);

            int len = max(len1, len2);
            if(len > maxLen){
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);

    }
};
