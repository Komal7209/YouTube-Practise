// first we need to sort each string then make that sorted string as key and from where we sorted as value to be stored in map
class Solution {
public:
    vector<vector<string>> ans ;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp = strs ;
        unordered_map<string, vector<string>> mp;
        for(int i=0; i < temp.size() ; i++)
		{
            string t = temp[i];
            sort(temp[i].begin(), temp[i].end());
            mp[temp[i]].push_back(t);
        }
        for(auto i:mp) ans.push_back(i.second);
        return ans;
    }
};