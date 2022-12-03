//tc: O(n)
//sc : O(n)    

class Solution {
public:
    class Comparator 
    {
        public:
        
        bool operator()(pair <int, char> a, pair <int, char> b)
        {
            return a.first < b.first;
        }
    };
    
    
    string frequencySort(string s) {
        
        unordered_map <char, int> mp;
        priority_queue < pair <int, char> , vector < pair <int, char> > , Comparator> p;
        for(auto x: s) // tc:O(n)
        {
            mp[x] ++;
             
        }
        
        for(auto x: mp) 
        {
             
            p.push({x.second, x.first});
        }
        
        string ans;
        vector <char> temp;
        while(!p.empty()) 
        {
            pair <int, char> q = p.top();
            int counter  = q.first;
            p.pop();
            
            while(counter> 0)
            {
                 ans.push_back(q.second);
                 counter --;
            }
         }
        return ans;
    }
};