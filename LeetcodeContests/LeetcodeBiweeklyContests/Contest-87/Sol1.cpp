
class Solution {
    
    int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int td(string s) {
        int m = s[1] - '0' + 10*(s[0] - '0');
        int d = s[4] - '0' + 10*(s[3] - '0');
        --m;
        while (m > 0) {
            d += md[m];
            --m;
        }
        return d;
    }
public:
    int countDaysTogether(string sa1, string sa2, string sb1, string sb2) {
        int a1 = td(sa1), a2 = td(sa2), b1 = td(sb1), b2 = td(sb2);
       
       int ans = 0;
        for (int i = 0; i < 370; ++i) {
            if (a1 <= i && i <= a2 && b1 <= i && i <= b2) {
                ++ans;
            }
        }
        return ans;
    }
};