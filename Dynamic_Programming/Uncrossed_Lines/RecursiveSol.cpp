class Solution{
   private:
        int solve(vector<int>& nums1, vector<int>& nums2,int n,int m)
    {
        int option1 =0, option2 = 0, option3 = 0;
        if(n<=0 || m<=0)
            return 0;
        
        if(nums1[n-1] == nums2[m-1])
        {
           return 1+solve(nums1,nums2,n-1,m-1);
        }
        else
        {
            option1=solve(nums1,nums2,n,m-1);
            option2=solve(nums1,nums2,n-1,m);
            return  max({option1,option2}); 
        }
    }
    
  public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1,nums2,nums1.size(),nums2.size());
    }
};