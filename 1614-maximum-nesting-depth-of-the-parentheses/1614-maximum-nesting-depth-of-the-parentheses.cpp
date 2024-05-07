class Solution
{
    public:
        int maxDepth(string s)
        {
            int ans = 0;
            int count = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '(')
                {
                    count++;
                    ans = max(ans, count);
                }
                else if (s[i] == ')')
                    count--;
                else
                {
                    ans = max(ans, count);
                }
            }
            return ans;
        }
};