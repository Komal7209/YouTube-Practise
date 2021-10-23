//Two pointer
//TC: O(n)
//SC:O(1)

class Solution {
public:
    /*
    int findMin(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<right)
        {
            if(nums[left]<=nums[right]) // as we are in correct range so we just need to stay in that
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return nums[left];  
    }
    */
    //TC:O(logn) , worst case i.e when duplicates are there then O(n)
    
    int findMin(vector<int>& nums) {
         int start=0,end=nums.size()-1;
         while(start<end){
             int mid= start+(end-start)/2; 
             if(nums[mid]<nums[end])
                 end=mid;                
             else if(nums[mid]>nums[end]) // this simply refers we  need to change are searching space
                 start=mid+1;         
             else                        // this is the correct searching space
                 end--;                  // this contributes to linear search when all three are equal
         }
         return nums[end];
    }
};