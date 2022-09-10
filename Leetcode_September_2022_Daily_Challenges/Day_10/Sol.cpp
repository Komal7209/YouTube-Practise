class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        if (k == 0 || prices.size() == 0) return 0;
               
        vector<int>profit(k+1, -1);
        vector<int>cost(k+1, INT_MAX);

        profit[0] = 0;
         
        // it runs k times for each price, i.e taking that price what is result for next k selections
        for (int price: prices) {
            for (int i = 0; i < k; i++) {
               
                cost[i+1] = min(cost[i+1], price - profit[i]);// filling up cost array // we should have min cost for max profit 
                profit[i+1] = max(profit[i+1], price - cost[i+1]);// filling up profit array
            }
        }
        return profit[k];
    }
};