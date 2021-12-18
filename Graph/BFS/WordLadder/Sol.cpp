class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>store;
        
        for(string s: wordList){ // storing all words given in our word list
            store.insert(s);        
        }

      if(!store.count(endWord)) return 0; // i.e our wordlist was not containing that word
        
        // performing bfs
        queue<string>q;
        q.push(beginWord);
        
        int depth =0;
        
        while(!q.empty()){
            depth++;
        int size = q.size();
        while(size--){
            
            string curr = q.front();
            
            q.pop();
            
            for(int i =0; i<curr.size(); i++){
                string temp = curr;             // because next we will be modifying our temp string
                
                for(int c =0; c<26; c++){

                    temp[i] = c+'a';
                
                    if(temp == curr) continue;
                    if(temp == endWord) return depth+1;
                    if(store.count(temp)){
                        q.push(temp);
                        store.erase(temp);
                    }
                  }
                } 
             } 
          }       
        return 0;
    }
};