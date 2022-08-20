class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& a) {
        
        vector<int>id(s.length()+1, 0);
        for(int i=0;i<a.size();i++)
        {
            int x=a[i][0], y=a[i][1], z=a[i][2];
            if(z==1)
            {
                id[x]+=1;
                id[y+1]-=1;
            }
            else{
                id[x]+=-1;
                id[y+1]-=-1;
            }
            
        }
        for(int i=1;i<id.size();i++)
        {
            id[i]+=id[i-1];
        }
        for(int i=0;i<id.size();i++)
        {
            id[i]%=26;
            if(id[i]>0)
            {
                while(id[i]>0){
                    if(s[i]=='z'){
                        s[i]='a';
                        id[i]--;
                    }
                    
                    else {
                        s[i]++;
                        id[i]--;
                    }
                }
            }
            else if(id[i]<0){
                 while(id[i]<0){
                    if(s[i]=='a'){
                        s[i]='z';
                        id[i]++;
                    }
                    else {
                        s[i]--;
                        id[i]++;
                    }
                }
            }
        }
        return s;
        
    }
};