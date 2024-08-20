class Solution
{
    public:
        string solve(int n)
        {
            if (n == 1)
                return "1";
            string temp = solve(n - 1);
            int count = 0;
            int prev = -1;
            string a = "";
            for (int i = 0; i < temp.size(); i++)
            {
                if (prev == -1)
                {
                    count = 1;
                    prev = temp[i] - '0';
                    continue;
                }
                if (prev + '0' == temp[i])
                {
                    count++;
                }
                else
                {
                    a += count + '0';
                    a += prev + '0';
                    count = 1;
                    prev = temp[i] - '0';
                }
            }

            a += count + '0';
            a += temp[temp.size() - 1];

            return a;
        }

    string countAndSay(int n)
    {
        return solve(n);
    }
};