class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int x : numSet) {
            if (numSet.count(x - 1) == 0) {
                int length = 0;
                while (numSet.count(x + length)) {
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};
