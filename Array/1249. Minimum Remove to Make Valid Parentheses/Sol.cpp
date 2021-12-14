class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {

        // 1
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                count++;
            else if (s[i] == ')'){
                if (count != 0)
                    count--;
                else
                    s[i] = '#';
            }
        }

        // 2
        count = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                count++;
            else if (s[i] == '('){
                if (count != 0)
                    count--;
                else
                    s[i] = '#';
            }
        }

        // 3
        string ans;
        for (int i = 0; i < s.length(); i++)
            if (s[i] != '#')
                ans += s[i];

        return ans;
    }
};