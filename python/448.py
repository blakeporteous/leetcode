class Solution:
    def findDisappearedNumbers(self, nums: list[int]) -> list[int]:

        seen = [0] * (len(nums) + 1)
        notseen = []
        
        for n in nums:
            seen[n] = 1
        
        for i in range(1, len(seen)):
            if seen[i] == 0:
                notseen.append(i)

        return notseen
            
