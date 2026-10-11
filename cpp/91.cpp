class Solution {
public:
    int numDecodings(string s) {

        int one = 1;
        int two = 0;

        for(int i = s.size() - 1; i >= 0; i--) {

            int num = s[i] - '0';
            int current = 0;

            if(num != 0) {
                current = one;

                if(i + 1 < s.size()) {
                    int two_digit = num * 10 + (s[i + 1] - '0');

                    if(two_digit >= 10 && two_digit <= 26) {
                        current += two;
                    }
                }
            }

            two = one;
            one = current;
        }

        return one;
    }
};
