class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        //time complexity is n as we used only 1 pass(for)
        
        
        int max_reach=0;  // it denotes the current value of the no. which is at particular current index and                                //according which we can jump to other numbers 
        
        for(int i =0 ; i<nums.size(); i++){
            if(nums[i] +i > max_reach) // first check (if it is 3 then previous value was 3 according to which it
                max_reach = nums[i] +i;  //could jump to next 1st, next 2nd, next 3rd number) 
            if( max_reach == i)// second check i.e if we are stuck at current index then we will break
                break;
        }
      return max_reach >= nums.size()-1;  
    } 
};