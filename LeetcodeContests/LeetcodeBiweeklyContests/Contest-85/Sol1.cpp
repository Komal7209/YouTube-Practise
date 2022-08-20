class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int cnt = INT_MAX;
        
        for( int i =0; i<= blocks.size()-k; i++)
        {
            int c =0;
            for( int j =i; j<i+k; j++) // k
            {
                if(blocks[j]!= 'B')
                    c++;
            }
            cnt = min(cnt,c);
        }
        return cnt;
    }
};