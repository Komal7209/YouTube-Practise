class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        
        int cnt=0;
        string present =s;
        while(1)
        {
            int haszerone=0;
            for(int i=0;i<s.length();i++)
            {
                if(i+1<s.length())
                {
                    if(s[i]=='0' and s[i+1]=='1'){
                        haszerone=1;
                        swap(present[i], present[i+1]);
                    }
                }
            }
            s=present;
            if(haszerone)cnt++;
            if(!haszerone)break;
           
        }
        return cnt;
    }
};