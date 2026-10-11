class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char, int> values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int number = 0;

        for (int i = 0; i < s.size(); i++) {
            char current = s[i];

            if(i < s.size() - 1 && values[s[i]] < values[s[i + 1]]) {
                number += values[s[i+1]] - values[s[i]];
                i++;
            } else {
                number += values[s[i]];
            }
        }

        return number;
    }
};
