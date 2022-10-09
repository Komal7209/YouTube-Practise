class Solution {
public:
    
    char low(vector<int> & freq){    // this function return the smallest char present
        
        for(int i=0;i<26;i++){
            if(freq[i]!=0)return 'a'+i; // converting index to char
        } 
        return 'z';  
    }
    
    string robotWithString(string s) {
        
        stack<char> st;
        string ans="";  
        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        
        for(char c:s){
            st.push(c);
             freq[c-'a']--; 
            while(st.size()>0 && st.top()<=low(freq)){
                char x = st.top(); 
                ans+= x;
                st.pop();  
            }    
        }

        return ans;
      
    }
};