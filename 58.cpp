class Solution {
public:
    int lengthOfLastWord(string s) {

        char one;
        char two = ' ';
        int count = 0;

        for(int i = s.size() - 1; i >= 0; i--) {

            one = s[i];

            if(one != ' ') {
                count += 1;
            }

            if(one == ' ' && count > 0) {
                return count;
            }

            two = one;
        }

        return count;
    }
};
