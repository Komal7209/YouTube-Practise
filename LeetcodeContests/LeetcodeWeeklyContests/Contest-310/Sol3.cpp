class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
		
        sort(intervals.begin(), intervals.end());
        
		// min heap
        priority_queue<int,vector<int>,greater<int>> heap;
        heap.push(intervals[0][1]); // pushing the second element of 1st row
        
        int ans = 1;
        for(int i=1; i<intervals.size(); i++){
			
            if(intervals[i][0] <= heap.top()){ // as heap top has ending point of a particular grp
                heap.push(intervals[i][1]); // new grp added
                cout<<"in if: "<<intervals[i][1]<<"\n";
            }
            else{
                heap.pop(); // because we already have 1 ele of same grp
                heap.push(intervals[i][1]);
                  cout<<"in else: "<<intervals[i][1]<<"\n";
            }
        }
        
        return heap.size();
    }
};