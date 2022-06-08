//TC: O(n)
//SC:O(1)

class Solution {
private:
        bool isPalindrome(string s){
            int left =0, right = s.length()-1;
            
            while(left<=right){
              if(s[left++]!=s[right--])
                  return false;
            }
            return true;
        }
public:
    int removePalindromeSub(string s) {
        if(isPalindrome(s)) return 1;
        else return 2;
    }
};