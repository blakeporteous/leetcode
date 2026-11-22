class Solution {
public:
    string minWindow(string s, string t) {
        if(t == "") return "";

        unordered_map<char, int> countT;
        unordered_map<char, int> window;

        for(char c : t){
            countT[c]++;
        }

        int have = 0;
        int need = countT.size();
        pair<int,int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        for(int r = 0; r < (int)s.size(); r++){
            char c = s[r];
            window[c]++;

            if(countT.count(c) && window[c] == countT[c]){
                have++;
            }

            while(have == need){
                // update new minimum result
                if((r - l + 1) < resLen){
                    res = {l, r};
                    resLen = (r - l + 1);
                }
                // pop from left
                window[s[l]] -= 1;
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    have -= 1;
                }
                l += 1;

            }
        }

        return resLen != INT_MAX ? s.substr(res.first, resLen) : "";
    }
};
