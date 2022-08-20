

// return min number of fuel stations
/*
TC: O(NlogN)
SC: O(N)
*/

class Solution {
public:
    int minRefuelStops(int target,int curfuel, vector<vector<int>> s) {
        
        int i = 0, res=0; 
        priority_queue<int>pq; // fuels added
        while(curfuel < target) {
              res++;
            while (i < s.size() && s[i][0] <= curfuel) //curr position less than the initial fuel or present fuel
                    pq.push(s[i++][1]);
           
            if (pq.empty()) 
                   return -1;
            
            curfuel += pq.top(), pq.pop(); // updated with fuel i.e this much distance more we can go
        
        }
        return res;
    }
};

