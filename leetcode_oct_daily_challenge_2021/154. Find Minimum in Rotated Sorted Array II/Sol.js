/**
 * @param {number[]} nums
 * @return {number}
 */
 var findMin = function(nums) {
    var left =0, right = nums.length-1;
    
    while(left<right){
        if(nums[left]<=nums[right])
            right--;
        else            
            left++;
    }
    return nums[left];
};