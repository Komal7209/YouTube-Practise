class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int res = logs[0][0];
        int Max = logs[0][1];
        for (int i =1; i< size(logs); i++)
        {
            if (logs[i][1]-logs[i-1][1]>Max)
            {
                res = logs[i][0];
                Max = logs[i][1]-logs[i-1][1];
            }
            else if (logs[i][1]-logs[i-1][1]==Max and res>logs[i][0]) // for equal case, then we need smaller id out of both
            {
                res = logs[i][0];
            }
        }
        return res;
    }
};
