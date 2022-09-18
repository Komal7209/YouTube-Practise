class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1, temp =1;
        if(s.size() == 1) return 1;
        
        
         for( int i = 1; i<s.size(); i++)
         {
             if(s[i]-s[i-1] == 1)
             {
                temp++;  
             }
             else
             {
                 ans = max(ans, temp);
                 temp =1;
             }
         }
           
        ans = max(ans, temp);
        return ans;
    }
};