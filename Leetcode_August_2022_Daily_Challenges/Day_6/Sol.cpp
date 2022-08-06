class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        

         int T = minutesToTest/minutesToDie;   //Trial count          
        return (int)ceil(log(buckets)/log(T+1));
       
    }
};