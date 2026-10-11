class Solution {
public:
    bool isPalindrome(string s) {

        string check;

        for(int i=0; i < s.size(); i++) {
            if(isalnum(s[i]))
            {
                check += tolower(s[i]);
            }
        }

        for(int j=0; j < check.size()/2; j++) {
            if(check[j] != check[check.size() - 1 - j]) 
            {
                return false;
            }
        }
        return true;
    }
};
