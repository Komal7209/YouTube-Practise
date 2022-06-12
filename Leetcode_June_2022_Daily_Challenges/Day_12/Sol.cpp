class Solution {
   public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int curr_sum = 0, max_sum = 0, left = 0;
        
        for (int num : nums) {
            
            while (seen.count(num)) { 
                
                curr_sum -= nums[left]; // excluding first ele from sum
                seen.erase(nums[left]); // erasing required as we are doing all this inside while loop
                left += 1;
            }
            curr_sum += num; // adding new element each time
            seen.insert(num); // updating index each time
            max_sum = max(max_sum, curr_sum);
        }
        
        return max_sum;
    }
};