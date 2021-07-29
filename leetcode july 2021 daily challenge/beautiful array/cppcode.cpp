class Solution {
public:
     vector<int> beautifulArray(int N) {
        vector<int> res = {1};
        while (res.size() < N) {
            vector<int> tmp;
            for (int i : res){
                if (i * 2 - 1 <= N) {
                    tmp.push_back(i * 2 - 1);
                cout<<"i*2 -1 "<<i*2 -1 <<'\n';
                }
            }
            for (int i : res) {
                if (i * 2 <= N){
                    tmp.push_back(i * 2);
                    cout<<"i*2 "<<i*2<<'\n';
                }
            }
            res = tmp;
             cout<<"res ";
            for(int i :res){
            cout<<i<<" ";
            }
            cout<<'\n';
        }
        return res;
    }
};