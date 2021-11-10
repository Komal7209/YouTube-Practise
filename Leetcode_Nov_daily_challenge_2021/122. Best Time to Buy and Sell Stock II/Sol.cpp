class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // as multiple transactions are allowed, so thats why we could add up variation subtractions together
        
        int n = prices.size(), maxprofit = 0;
        
        for( int i =1; i<n; i++){
            
            if(prices[i]> prices[i-1])
                maxprofit += prices[i] - prices[i-1];
            
        }     
        
        return maxprofit;
        
    }
};