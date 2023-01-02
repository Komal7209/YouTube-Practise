class Solution {
public:
    bool capital(string word, int index){
         if(word[index]>'Z' or word[index]<'A') return false;
         else return true;         
    }
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n ==1) return true;
        
        if(capital(word, 0) and capital(word, 1)){ //for all capital case     
            for(int i = 2 ; i< word.size() ; i++){
                if(!capital(word,i)) return false;                
            }
        }
        else{//if from 2nd char is capital either in all small or 1st capital
            for(int i = 1; i<word.size(); i++){
                if(capital(word, i))
                    return false;
            }
        }
        // return true if doesnt return false in else case(i.e any capital in between) or  
        return true;     
    }
};