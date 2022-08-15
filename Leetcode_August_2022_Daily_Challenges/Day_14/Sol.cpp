class Solution {
private:
    unordered_map<string, vector<string>> adjList;
    vector<string> currPath;
    vector<vector<string>> shortestPaths;

    // for keeping check on criteria of having 1 char difference
    // for building the graph// make neigbors of this word// for checking if that word exists in our set or not  
    vector<string> findNeighbors(string &word, unordered_set<string> &wordList) {
        vector<string> neighbors;

        for (int i = 0; i < word.size(); i++) {
            char oldChar = word[i];

            // replace the i-th character with all letters from a to z except the original character
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;

                // skip if the character is same as original or if the word is not present in the
                // wordList
                if (c == oldChar || !wordList.count(word)) {
                    continue;
                }
                neighbors.push_back(word);
            }
            word[i] = oldChar;
        }
        return neighbors;
    }

    void bfs(string& beginWord, string& endWord, unordered_set<string>& wordList) {
        queue<string> q;
        q.push(beginWord);

        // remove the root word which is the first layer
        if (wordList.count(beginWord)) {
            wordList.erase(wordList.find(beginWord));
        }

        unordered_map<string, int> isEnqueued;
        isEnqueued[beginWord] = 1;

        while (!q.empty()) {
            // visited will store the words of current layer
            vector<string> visited;

          
           for (int i = q.size() - 1; i >= 0; i--) { // for each layer 
                string currWord = q.front();
                                 q.pop();

                // findNeighbors will have the adjacent words of the currWord
                vector<string> neighbors = findNeighbors(currWord, wordList);
                for (auto word : neighbors) { //node in neighbor to currnode(parent)
                   
                    visited.push_back(word);
                    // now time to connect all neighbors
                    // add the edge from word to currWord in the list
                    //word->currword: ted->red , rex->red
                    adjList[word].push_back(currWord); // stores the children of present node

                    if (!isEnqueued.count(word)) { // for giving it the next level
                        q.push(word);
                        isEnqueued[word] = 1;
                    }
                }
           
            }
            //removing the words of the previous layer //so that as we proceed to next level, we are able to start fresh
            for (int i = 0; i < visited.size(); i++) {
                if (wordList.find(visited[i]) != wordList.end()) {
                    wordList.erase(wordList.find(visited[i]));
                }
            }
        }
    }
    
    // backtracking the graph which was earlier made for finding the paths from end word to begin word 
    void backtrack(string &source, string &destination) {
        // store the path if we reached the endWord
        if (source == destination) {
            shortestPaths.push_back(vector<string>(currPath.rbegin(), currPath.rend()));
        }
   
        for (int i = 0; i < adjList[source].size(); i++) {
         
            currPath.push_back(adjList[source][i]); // creating req path here
            backtrack(adjList[source][i], destination); // now bactracking from new node
            currPath.pop_back();
        }
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        // copying the words into the set for efficient deletion in BFS
        unordered_set<string> copiedWordList(wordList.begin(), wordList.end());
        // build the DAG using BFS
        bfs(beginWord, endWord, copiedWordList);

        // every path will start from the endWord
        currPath = {endWord};
        // traverse the DAG to find all the paths between endWord and beginWord
        backtrack(endWord, beginWord);

        return shortestPaths;
    }
};