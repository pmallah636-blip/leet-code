#include <string>
#include <stack>

class Solution {
public:
    int calculate(string s) {
        std::stack<int> st;
        long long num = 0;
        int res = 0;
        int sign = 1;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            char c = s[i];

            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                res += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += sign * num;
                num = 0;
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
        }

        res += sign * num;
        return res;
    }
};
