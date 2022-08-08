// TC: (nlogn)
// SC: O(n)

// extend , replace and return the length
class Solution {
private: 
    // returns index of target
                // prev_ele  //present_ele
    int binSearch(vector<int>lis, int target){
        int l =0, r = lis.size()-1, ans = INT_MAX;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            
    // eg: replacing 10 i.e lis[mid] with target i.e 9
            if(lis[mid]>=target){ // lower_bound
                ans = min(ans, mid);//because it want just greater
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        if(ans != INT_MAX) return ans;
        else return -1;
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
       
        vector<int> lis;
        lis.push_back(nums[0]); // so that we have atleast 1 number inside it to compare with
        
        for( int i=1; i<nums.size(); i++){
            int index = binSearch(lis, nums[i]); // index, so that we know in lis array where we need to place our present ele
            
            if(index == -1){ // represents we dont have valid index by which we want to replace // extend
                lis.push_back(nums[i]);
            }
            else{
                lis[index] = nums[i];   // replace the element 
            }   
        }
        
        return lis.size();
    }
};