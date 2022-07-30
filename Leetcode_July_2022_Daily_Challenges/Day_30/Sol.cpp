class Solution {
    private:
            // count frequency of each character in a word
        vector<int> countFreq(string& word){
            vector<int> freq(26);
            for(auto& c : word)
                freq[c - 'a']++;
            return freq;
        }

    
public:

        vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
           
            vector<int> Maxfreq(26); 
            vector<string> ans;
            
            // maintains frequency of word B to check for wordA's each word is capable for universal word or not
            for(auto& word : B){
                vector<int> freq = countFreq(word);            
                for(int i = 0; i < 26; i++)
                    Maxfreq[i] = max(Maxfreq[i], freq[i]);
            }   
            
            // checking if present word is universal or not
            for(auto& word : A){
                vector<int> freq = countFreq(word);            
                int i = 0;
                for( ;i < 26; i++)
                    if(freq[i] < Maxfreq[i]) 
                        break;
                if(i == 26) ans.push_back(word);
            }
            return ans;
    }  
};

