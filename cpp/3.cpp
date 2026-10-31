class Solution {
public:
int lengthOfLongestSubstring(string s) {

    unordered_set<char> window;
    int left = 0, best = 0;

    for (int right = 0; right < s.length(); right++) {
        // while s[right] is in window: erase s[left], left++
        // insert s[right]
        // update best
        while (window.count(s[right])) {
            window.erase(s[left]);
            left++;
        }

        window.insert(s[right]);
        best = max(best, right - left +1);

    }

    return best;
}
};
