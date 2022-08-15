class Solution{
    public:
        string smallestNumber(string pattern) {
                string result;
                stack<int> s;
                for (int i = 0; i <= pattern.length(); i++)
                {
                    s.push(i + 1); // keep pushing in stack until you encounter a 'I'
                    if (i == pattern.length() || pattern[i] == 'I')
                    {
                        while (!s.empty())
                        {
                            result += to_string(s.top());
                            s.pop();
                        }
                    }
                }

                return result;
            }
};
