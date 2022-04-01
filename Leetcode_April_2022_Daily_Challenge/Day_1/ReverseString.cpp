class Solution {
public:    
    // recursive solution
    
    void reverseStringRecursive(vector<char>&s, int left, int right ){
        if(left >=right) return;
        char tempString = s[left]; 
        s[left++] = s[right]; 
        s[right--] = tempString;
        reverseStringRecursive(s, left, right);        
    }
    
    
   void reverseString(vector<char>& s) {
                           // , left, right     
      reverseStringRecursive(s, 0, s.size()-1);
   }
 };
 

 /*
 Iterative

 class Solution {
public:
    
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            char tmp = s[left];
            s[left ++] = s[right];
            s[right --] = tmp;       
        }
        
    }
};
 
 
 */