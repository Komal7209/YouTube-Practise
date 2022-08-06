class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        
        map<int, int>mp;
        vector<vector<int>>arr;
        
        for( auto i: items1){
            mp[i[0]]+=i[1];
        }
        
        for(auto i: items2){
            mp[i[0]]+=i[1];
        }
        
        for(auto i: mp){
            arr.push_back({i.first, i.second});
        }
        return arr;
    }
};