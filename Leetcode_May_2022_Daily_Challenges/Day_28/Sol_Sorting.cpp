//TC:O(nlogn)
//SC:O(1)

class Solution {
    public:
     int missingNumber(vector<int>nums) {
        sort(nums.begin(), nums.end());

        // Ensure that n is at the last index
        if (nums[nums.size()-1] != nums.size()) {
            return nums.size();
        }
        // Ensure that 0 is at the first index
        else if (nums[0] != 0) {
            return 0;
        }

        // If we get here, then the missing number is on the range (0, n)
        for (int i = 1; i < nums.size(); i++) {
            int expectedNum = nums[i-1] + 1;
            if (nums[i] != expectedNum) {
                return expectedNum;
            }
        }

        // Array was not missing any numbers
        return -1;
    }
}