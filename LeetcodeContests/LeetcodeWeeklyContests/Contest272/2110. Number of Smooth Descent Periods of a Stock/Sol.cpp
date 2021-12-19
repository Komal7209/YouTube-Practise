#define ll long long int

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        ll ans = 0;
        ll prev = INT_MIN;
        
        for(int i =0, count =0; i<prices.size(); i++){
            
            if(prices[i]+1 == prev){// descending order
                count++;
            }
            else{                   // single element
                count =1;
            }
            
            prev = prices[i];
            ans+=count; 
        }
        return ans;    
    }
};

// Tc:O(n)
// SC:O(1)