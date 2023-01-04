class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =nums.size(), givenSum = 0, totalSum = (n*(n+1)/2); // missing num = n
        
        
        for(int i =0; i<n; i++){
            givenSum+=nums[i]; // missingnum ^= i^nums[i];
        }
        
        return totalSum - givenSum; // missing num
    }
};