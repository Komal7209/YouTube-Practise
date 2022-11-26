class Solution {
public:
    int numberOfCuts(int n) {
        if(n < 2) return 0;
        if(n%2 == 0) return n/2;
        else
            return n;
        
    }
};

// tc: O(1)
// sc: O(1)