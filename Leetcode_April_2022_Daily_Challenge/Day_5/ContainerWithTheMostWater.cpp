// TC: O(n)
// SC: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left =0, right = n-1, maxArea = 0;
        
        while(left<right){
            maxArea = max(maxArea, min(height[left],height[right])*(right-left));
        if(height[left]<height[right])
            left++;
            else
            right--; 
        }
     return maxArea;   
    }
};