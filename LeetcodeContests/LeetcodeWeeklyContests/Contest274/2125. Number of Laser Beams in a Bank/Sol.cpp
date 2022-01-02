class Solution {
public:
    // just count all laser in previous row multiplied with current rows laser bcoz laser beams are only activated when it gets some other laser beam in next row
    // TC: O(n)
    //SC: O(n)
    
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int>counts;
        
        for(int r =0; r<n; r++){
            int ct = count(bank[r].begin(), bank[r].end(), '1'); // std stl count
            if(ct == 0)
                continue;
            counts.emplace_back(ct);
        }
        long long ans =0;
        
        n = counts.size();
        
        for(int i =0; i+1<n; i++){
            ans += counts[i]*counts[i+1]; // prev row *present row count
        }
        return ans;
        
    }
};
*/
class Solution {
public:
    // just count all laser in previous row multiplied with current rows laser bcoz laser beams are only activated when it gets some other laser beam in next row
    //TC: O(n)
    //SC:O(1)
    int numberOfBeams(vector<string>& bank) {
        int pOnes=0; int res=0;
        
        for(string s: bank){
            int count=0;
            for(char ch: s){ // for a single row
                if(ch=='1'){
                    count++;
                }
            }
           if(count>0){
                res+=(count*pOnes);
                pOnes=count;  // due to this we are able to eliminate usage of extra space
            }
        }
        return res;
       }
};
