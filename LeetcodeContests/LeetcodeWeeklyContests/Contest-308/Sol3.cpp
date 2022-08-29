class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
       
        int pref[100001];
        pref[0]=0;
        for(int i=1;i<g.size();i++)pref[i]=pref[i-1]+t[i-1];
        map<char,pair<int,pair<int,int>>>mp;
        for(char v: {'G', 'M', 'P'})
        {
            int cnt=0;
            int f=0, l=0;
            for(int i=0;i<g.size();i++)
            {
                for(int j=0;j<g[i].length();j++)
                {
                    if(g[i][j]==v){
                        if(!f){
                            f=i+1;
                        }
                        l=i+1;
                        cnt++;
                    }
                }
            }
            if(f==0)continue;
            mp[v]={cnt,{f, l}};
        }
        int ans=0;
        for(auto x: mp){
            ans+=x.second.first;
          
             ans+=pref[x.second.second.second-1];
        }
        return ans;
        
    }
};