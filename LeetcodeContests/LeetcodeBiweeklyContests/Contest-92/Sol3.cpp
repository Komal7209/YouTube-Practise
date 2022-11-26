// tc: O(nlogn)
// sc : O(n)

class Solution 
{
public:
    int bestClosingTime(string s) 
    {
        int totsum=0;
        int presum=0;
        int n=s.size();
        
        for(int i=0; i<n; i++)
        {
            if(s[i]=='Y') totsum++;
        }
        
        map<int, int> mp;
        mp[0] = totsum;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='Y')
            {
                presum++;
            }
            else
                presum--;
            
            mp[i+1] = totsum-presum;
                
        }
        
        
        int hour=n;
        int p=n;
        for(auto it:mp)
        {
            if(it.second < p)
            {
                hour=it.first;
                p = it.second;
            }
        }
        
        return hour;
        
    }
};