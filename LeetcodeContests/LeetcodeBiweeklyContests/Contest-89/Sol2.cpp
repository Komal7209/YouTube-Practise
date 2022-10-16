// tc: O(n)
// sc: O(1)

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int m = 1e9+7;
        vector<int> bint, ans;
        //create power array 
        for(int i = 0; i < 32; ++i){
            if((n & (1<<i)) != 0) bint.push_back(1<<i);
        }
        for(auto q: queries){
            int i = q[0];
            long p = bint[i++];
            while(i <= q[1]){
                p = (p * bint[i++])%m;
            }
            ans.push_back(p);
        }
        return ans;
    }
};