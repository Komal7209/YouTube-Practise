class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // as multiple transactions are allowed, so thats why we could add up variation subtractions together
        
        int days = prices.size(), maxprofit = 0;
        
        for( int day =1; day<days; day++){
            
            if(prices[day]> prices[day-1])
                maxprofit += prices[day] - prices[day-1];
            
        }     
        
        return maxprofit;
        
    }
};
