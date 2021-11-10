class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length, maxProfit =0;
        
        for(int i =1; i<n; i++){
            if(prices[i]>prices[i-1]){
                maxProfit += (prices[i]- prices[i-1]);
            }
        }
        return maxProfit;
    }
}