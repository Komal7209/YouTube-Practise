// TC: O(n*w)
// SC: O(1)

class Solution {
public:
    
    bool isPal (string s){
        int left =0, right = s.length()-1;
        while(left<=right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        string ans ="";
        
        for(int i =0; i<words.size(); i++){
            if(isPal(words[i])) {
                ans = words[i];
                break;
            }
        }
        
        return ans;
    }
};