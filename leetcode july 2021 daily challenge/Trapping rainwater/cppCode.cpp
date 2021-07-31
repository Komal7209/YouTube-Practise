// this says that water is trapped between different sized bars and between some huge bars which we need to return


// here two pointer in opposite aspects but
// first pointer fills using first_max variable 
// second pointer fills using second_max variable

class Solution {
public:
    int trap(vector<int>& height) {
        
        int left = 0, right = height.size()-1;
        int ans =0;
        int left_max =0, right_max=0;
        
        while(left<right){

            if(height[left]<height[right]){
                height[left] >= left_max?(left_max = height[left]): ans+=(left_max-height[left]);
                ++left;
            }
            else{
                height[right]>= right_max ? (right_max = height[right]): ans+=(right_max - height[right]);
                --right;
            }
        }
return ans;
    }
}; 