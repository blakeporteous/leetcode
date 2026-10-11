class Solution:
    def maxProfit(self, prices: list[int]) -> int:

        if not prices:
            return 0

        l,r=0,1
        maxP = 0
        
        while r != len(prices):

            if prices[l] < prices[r]:
                prof = prices[r] - prices[l]
                maxP = max(maxP, prof)
            
            else:
                l = r

            r+=1

        return maxP
        
