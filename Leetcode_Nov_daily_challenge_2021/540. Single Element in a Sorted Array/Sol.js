var singleNonDuplicate = function(nums) {
    
  let start = 0;
  let end = nums.length - 1;
  
  if(nums[0] !== nums[1]) return nums[0];
  if(nums[end] !== nums[end-1]) return nums[end];
  
  while(start <= end) {
      const mid = Math.floor((start + end) / 2);
      
      if(nums[mid] !== nums[mid-1] && nums[mid] !== nums[mid+1]) return nums[mid];
      
      if((mid%2 === 0 && nums[mid] === nums[mid+1]) || (mid%2 !== 0 && nums[mid] === nums[mid-1])) {
          start = mid;
      } else end = mid;
  }
};