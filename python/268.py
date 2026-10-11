class Solution:
    def missingNumber(self, nums: list[int]) -> int:

        length = len(nums)
        seen = [0] * (length + 1)

        for n in nums:
            seen[n] = 1
        
        for i, v in enumerate(seen):
            if v == -1:
                return i
        
