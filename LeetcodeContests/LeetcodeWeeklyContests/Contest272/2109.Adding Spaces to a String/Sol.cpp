// Tc:O(n)
//SC:O(1)

class Solution {
public:   
    string addSpaces(string s, vector<int>& spaces) {
        
        string ans;
        int j=0, count =0;
        
        for(auto i:s){
            if(j<spaces.size() and count == spaces[j])
                ans +=' ', j++;
            
            ans+=i;
            count++;
        }
        return ans;
        
    };
};