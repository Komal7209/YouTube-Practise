class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int>Sum;
        for(auto a : A) {
            for(auto b : B) {
                ++Sum[a+b];
            }
        }
        int count = 0;
        for(auto c : C) {
            for(auto d : D) {
                auto it = Sum.find(0 - c - d);
                if(it != Sum.end()) {
                    count += it->second;
                }
            }
        }
        return count;
    }
};