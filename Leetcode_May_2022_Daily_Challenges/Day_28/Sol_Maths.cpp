//TC: O(n)
//SC:O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =nums.size(), givenSum = 0, totalSum = (n*(n+1)/2);
        
        
        for(int i =0; i<n; i++){
            givenSum+=nums[i];
        }
        
        return totalSum - givenSum; 
    }
};