class Solution {
public:
    int numSquares(int n) {
        if(n<=3) return n;
        int count = n;
        
        for( int i=1; i*i<=n; i++){
            count = min(count, 1+numSquares(n-(i*i)));
        }
        return count;
    }
};