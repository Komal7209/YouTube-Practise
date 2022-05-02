// TC: O(n), SC: O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0, r = A.size()-1;
        while(l < r){
            while(l < r && A[l] % 2 == 0) l++;
            while(l < r && A[r] % 2 == 1) r--;
            int tmp = A[l];
            A[l] = A[r];
            A[r] = tmp;
        }
        return A;
    }
};