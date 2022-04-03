// TC:O(3*n) = O(n)
//SC:O(1)

class Solution {
private:
    // helper functions
    //tc:O(n)
        void reverse(vector<int>&nums, int start) {
        int i = start, j = nums.size() - 1;
            while (i < j) {
                swap(nums, i, j);
                i++;
                j--;
              }
        }
    //tc:O(n)
    void swap(vector<int>&nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;       // index of last second element
        // tc:O(n)
        while (i >= 0 && nums[i + 1] <= nums[i]) { // running this loop until we reach a pair where first number is smaller than second number //2,3,6,5,4,1 => 3
            i--;
        }
        // Now we got that ith element which is smaller than next i+1th element
        
        if (i >= 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) { // running this loop until we reach a pair where last finded number is smaller than now finded number //2,3,6,5,4,1
                j--;
            }
            swap(nums, i, j); // we need to swap these //2,4,6,5,3,1 => after swapping
        }
        reverse(nums, i + 1); // need to reverse all numbers after swapped number => reverse after 4 =>2,4,1,3,5,6
    }    
};