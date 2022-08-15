class Solution {
private:
    static bool compare(vector<long int>&a, vector<long int>&b){
        if(a[1]==b[1])
            return a[0]<b[0];
        return a[1]>b[1];
    }
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<long int,long int>mp;
        vector<vector<long int>>v;
        
        for(int i =0; i<edges.size(); i++){
            mp[edges[i]]+=i;         
        }
        
        for(auto i: mp){
           v.push_back({i.first, i.second}); 
        }
        
        sort(v.begin(), v.end(), compare);
       int ans = v[0][0];
        
        return ans;
    }
};

/*
// more optimised version of above:

    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n);
        for(int i = 0; i < n; i++){
            score[edges[i]] += i;
        }
        long long mx = INT_MIN;
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(score[i] > mx){
                mx = score[i];
                idx = i;
            }
        }
        return idx;
    }

*/


/*
//using graph:

int edgeScore(vector<int>& edges) {
    int n = edges.size();
    vector<vector<int>> graph(n);
    for(int i=0; i<n; i++)
        graph[edges[i]].push_back(i);

    long long resNode = 0, bestScore = 0;
    for(int i=0; i<n; i++){
        long long score = 0;
        for(long long child: graph[i])
            score += child;

        if(score > bestScore){
            resNode = i;
            bestScore = score;
        }
    }
    return resNode;
}

*/