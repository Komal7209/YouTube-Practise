class Solution {
public:
    int maximum69Number (int num) {
        
        string aux = to_string(num);
        int cnt =0;
        
        for( int i =0; i<aux.size(); i++)
        {
            if(aux[i] == '6' and cnt ==0)
            {
                aux[i] ='9';
                cnt++;
            }
        }
        
        return stoi(aux);
    }
};