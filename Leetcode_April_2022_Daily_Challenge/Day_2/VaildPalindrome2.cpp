// TC: O(n)
// SC: O(1)

class Solution {
private:
        bool checkNextIndex(string s,int left,int right){
        while(left<=right){
            if(s[left++]!= s[right--]) return false;
        }
        return true;
    }
public:  
    // checking normal pallindrome and then checking if letter before or letter after is making a pallindrome or not
         bool validPalindrome(string s) {
             
             int left = 0, right = s.size()-1;
             
             while(left<=right){
                 if(s[left]!=s[right]){
                     return checkNextIndex(s,left+1,right) || checkNextIndex(s,left,right-1);
                 }
                 else{
                     left++,right--;
                 }
             }
             return true;
         }    
};