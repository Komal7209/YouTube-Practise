// TC: O(nlogn)
// SC: O(n)

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
     map<int, string, greater<int> > mp;
        int i =0;
        for( ; i<heights.size(); i++)
        {
            mp.insert({heights[i], names[i]});
        }
        
        i =0;
        for(auto j: mp)
        {
            if(i<names.size())
            {
                names[i++] = j.second;
            }
        }
        return names;
    }
};