class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        string ans;
        int count =0;
        
        for( int i: s){
            st.push(i);
            while(st.top() == '*'){
                st.pop();
                count++;
            }
            while(count>0){
                st.pop();
                --count;
            }
            count = 0;
            
        }
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};