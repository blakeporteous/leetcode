class Solution {
public:
    int characterReplacement(string s, int k) {

        array<int, 26> count {};
        int l = 0, res = 0;

        for(int r = 0; r<s.size(); r++){
            count[s[r] - 'A']++;

            while((r - l + 1) - *max_element(count.begin(), count.end()) > k){
                count[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};
