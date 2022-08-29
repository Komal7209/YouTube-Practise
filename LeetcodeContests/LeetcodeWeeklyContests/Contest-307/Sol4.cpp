class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        
        long long totSum = 0;
        
        // calculate sum of all positive numbers, i.e maxSubseqSum (2^nth sum)
        for(int &num : nums)
        {
            if(num > 0)
                totSum += num;
            
            num = abs(num);
        }
        
        // sort ascending order
        sort(nums.begin(), nums.end());
        
        // maintain {subseqSum, index which we taken to reduce the sum}
        priority_queue<pair<long long, int>> pq;
        
        // push totSum - first num, num pos is 0
        pq.push({totSum - nums[0], 0});
        
        long long res = totSum, n = nums.size();
        
        while(--k)
        {
            pair<long long int , int> cur = pq.top(); pq.pop();
            
            res = cur.first;
            
            int idx = cur.second;
            
            if(idx < n - 1)
            {
                // generate next possible sum
                
                // pick curIdx and try with the next idx
                pq.push({res + nums[idx] - nums[idx + 1], idx + 1});
                
                // notPick curIdx and try with the next idx
                pq.push({res - nums[idx + 1], idx + 1});
            }
        }
        
        return res;
    }
};