// TC : O(n +26) = O(n)
// SC : O(26*26) = O(1)
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        vector<vector<int>>mp (26, vector<int>(26, 0));
        // [1][1] = 1
        int ans =0;
        
        // reverse and original are present
        for( string w : words)
        {
            if(mp[w[1]-'a'][w[0]-'a'])
            {
                ans += 4;
                mp[w[1]-'a'][w[0]-'a']--;
            }
            else
                mp[w[0]-'a'][w[1]-'a']++;          
        }
        
        for( int i =0; i<26; i++)
        {
           if(mp[i][i])
           {
               ans +=2;
               break;
           }
        }
        
        return ans;
    }
};