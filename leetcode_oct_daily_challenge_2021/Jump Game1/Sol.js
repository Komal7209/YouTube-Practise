var canJump = function(nums) {
    var maxReach =0;
    for(var i =0; i<nums.length; i++){
        if(nums[i]+i > maxReach) maxReach = nums[i]+i;
        if(maxReach == i) break;
    }
    return maxReach >= nums.length -1;
};