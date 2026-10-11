class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int lowest = prices[0];
        int profit;
        int highProfit = 0;

        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < lowest) {
                lowest = prices[i];
            } else {
                profit = prices[i] - lowest;

                if(highProfit < profit) 
                {
                    highProfit = profit;
                }
            }
        }

        return highProfit;
    }
};
