class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // productExceptSelf[i] is product of array except self.
        vector<int>productExceptSelf(n);
        
        productExceptSelf[0] = 1; // Without numbers to its left.
        
        // for prefixsum
        // without extra variable
        for (int i = 1; i < n; i++) {
            productExceptSelf[i] = productExceptSelf[i - 1] * nums[i - 1];
         
        }
        
        // Product of numbers to the right of current element.
        // with extra variable to keep track of right elements
        int productOfRightNums = 1;
        for (int i = n - 2; i >= 0; i--) {
            productOfRightNums = productOfRightNums * nums[i + 1];
            productExceptSelf[i] *= productOfRightNums;
            
        }
        
        return productExceptSelf;
    }
};