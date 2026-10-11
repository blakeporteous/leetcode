class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);  // size n+1, filled with 0s

        for (int i = 0; i <= n; i++) {
            int num = i;
            int bits = 0;
            
            while (num != 0) {
                int rem = num % 2;
                if (rem == 1) {
                    bits += 1;
                }
                num = num / 2;
            }
            ans[i] = bits;
        }

        return ans;
    }
};
