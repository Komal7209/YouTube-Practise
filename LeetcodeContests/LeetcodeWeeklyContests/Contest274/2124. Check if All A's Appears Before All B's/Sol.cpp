class Solution {
public:
    
    // Tc: O(n)
    //SC:O(1)
    bool checkString(string s) {
      // just check  for no outofbound and any a after b  
        for(int i =0; i<s.length(); i++) 
            if((s[i] == 'b') and (i+1 != s.length()) and (s[i+1] == 'a'))
                return false;        
    
    return true;
    }
};