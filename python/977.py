class Solution:
    def sortedSquares(self, nums: list[int]) -> list[int]:

        ret = []

        for num in nums:
            num_sq = num * num
            ret.append(num_sq)
        
        return sorted(ret)
        
