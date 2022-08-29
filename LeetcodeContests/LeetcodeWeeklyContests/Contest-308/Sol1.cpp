// TC: O(m*n)
// SC: O(n)


class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        int n = nums.size();
        int m = queries.size();
        
        sort(nums.begin(),nums.end()); // we are sorting, even if we require subsequence, because ques says to return size of subsequence not the number present in subsequence
        int sum = 0;
        vector<int> pre_sum;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            pre_sum.push_back(sum);           // storing prefix sum
        }
        
        vector<int> ans(m,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pre_sum[j] <= queries[i]) ans[i] = j+1;          // wherever we got the max subsequence sum for i just update that, because here we will be able to figure out with maximum size required
                else break;
            }
        }
        return ans;
    }
};