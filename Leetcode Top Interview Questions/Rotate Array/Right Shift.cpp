class Solution {
public:
    
    // by using inbuilt reverse function of cpp stl
    // array is considered 0 indexed
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;   
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+ k);
        reverse(nums.begin()+k, nums.end());
    }
};
