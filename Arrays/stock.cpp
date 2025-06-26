/*
Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/

class Solution {
    public:
    int maxProfit(vector<int>& prices)
    {
        int buy = prices[0];
        int profit = 0;
        for(int i=0;i<prices.size();i++)
        {
            if(buy>prices[i])
            buy = prices[i];

            profit = max(profit,prices[i]-buy);
        }
        return profit;
    }
};

//Intution 
/*
The goal is to buy at the lowest price and sell at the highest price after buying.

We track the minimum price so far as we iterate through the list (i.e., the best "buy" price).

For each day's price, we calculate the profit we’d make if we sold that day (i.e., current_price - min_price_so_far).

We keep updating the maximum profit encountered.

This ensures we always consider the most profitable single transaction.

Time: O(n) | Space: O(1)

*/