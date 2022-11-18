//TC: O(1)
// SC: O(1)

class Solution {
private:
    
     int keepDividingWhenDivisible(int dividend, int divisor) {
        while (dividend % divisor == 0) {
            dividend /= divisor;
        }
        return dividend;
    }
public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }

        for (int factor : {2, 3, 5}) {
            n = keepDividingWhenDivisible(n, factor);
        }

        return n == 1;
    }
   
};
