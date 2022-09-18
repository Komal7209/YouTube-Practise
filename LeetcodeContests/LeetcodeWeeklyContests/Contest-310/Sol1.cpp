// TC: O(nlogn)
//SC: O(n)

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        int count =0, ans =-1;
        
        for( int i : nums){
            mp[i]++;
        }
        
        for(auto i: mp){
            int temp = i.first;
           
            
            if(temp %2 == 0 && i.second > count){
                
                count = i.second;
                  ans = i.first;
                }           
        }
        return ans;
    }
};