class Solution
{
    public:
        int myAtoi(string s)
        {
            long long ans = 0;
            int i = 0;
            int len = s.size();
            bool flag = false;	//+ve
            while (i < len && s[i] == ' ') i++;
            if (s[i] == '-')
            {
                i++;
                flag = true;
            }
            else if (s[i] == '+') i++;
            while (i < len)
            {
                while (s[i] >= '0' && s[i] <= '9')
                {
                    ans = ans * 10;
                    if (ans > INT_MAX || ans < INT_MIN) break;
                    ans = ans + (s[i] - '0');
                    i++;
                }
                break;
                i++;
            }
            if (flag) ans *= -1;
            if (ans >= INT_MAX) return INT_MAX;
            if (ans <= INT_MIN) return INT_MIN;
            return ans;
        }
};