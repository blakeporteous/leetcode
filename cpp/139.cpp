class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<int> dp(s.size() + 1, 0);
        dp[s.length()] = true;

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int w = 0; w < wordDict.size(); w++) {
                
                if (i + wordDict[w].length() <= s.length() &&
                    s.substr(i, wordDict[w].length()) == wordDict[w]) {
                    
                    dp[i] = dp[i + wordDict[w].length()];
                    
                    if (dp[i])
                        break;
                }
            }
        }

        return dp[0];
    }
};
