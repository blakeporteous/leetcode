class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0){
            return false;
        }

        int dummy = x;
        int digit;
        long long reversed = 0;

        while(x>0){

            digit = x % 10;
            reversed = reversed * 10 + digit;
            x = x / 10;

        }

        if(dummy == reversed) {
            return true;
        } else {
            return false;
        }
    }
};
