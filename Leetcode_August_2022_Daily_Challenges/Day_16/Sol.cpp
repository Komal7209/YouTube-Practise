
class Solution {
public:
    int firstUniqChar(string s) {
        
        int count[26] = {0};
        
       // for(char c:s){
        //   count[c-'a']++;
        //}
        // or
        for(int i =0; i<s.length(); i++){
            count[s[i] -'a']++;
        }
        
        for(int i =0; i<s.length(); i++){
            if(count[s[i]-'a'] ==1) return i;
        }
        return -1;
    }
};

// TC: O(N)
//SC: O(1) // As hashmap ccan have atmax 26 characters