public class Solution {
    public int maxProfit(int[] prices) {
        int min = 0;
        int profit = 0;
        
        for(int i = 1; i < prices.length; i++) {
            if(prices[min] > prices[i]) min = i;
            else profit = Math.max(profit, prices[i] - prices[min]);
        }
        
        return profit;
    }
}