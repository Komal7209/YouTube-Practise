// TC: O(pow(2,n))
// SC: O(pow(2,n))

// bfs
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
               
               // num , level
        queue<pair<int,int>> q;
        for(int i=1;i<10;i++){
            q.emplace(i, 1);
        }
        
        vector<int> result;
        
        while(!q.empty()){
            auto [num, level] = q.front();
            q.pop();
            
            if(level == N)
                result.emplace_back(num);
            
            int digit = num%10;
            
            // getting by adding up
            if( (digit + K) < 10 && (level + 1) <= N){
                int m = num * 10 + (digit+K);
                q.emplace(m, level + 1);
            }
            // getting by subtracting
            if(K>0 && digit - K >= 0 && (level + 1) <= N){
                int m = num * 10 + (digit-K); // making new number by shifting previous digit
                q.emplace(m, level + 1);
            }
            
        }
        return result;
    }
};
