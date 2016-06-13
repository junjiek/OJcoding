class Solution {
    static const int maxDiv10 = INT_MAX / 10;
    bool isDigit(char c) {
        return (c <= '9' && c >= '0')
    }
public:
    int myAtoi(string str) {
        int n = (int)str.size();
        int i = 0;
        while (i < n && str[i] == ' ')
            i++;
        int sign = 1;
        if (i < n && str[i] == '+') {
            i ++;
        } else if (i < n && str[i] == '-') {
            i ++;
            sign = -1;
        }
        int num = 0;
        while (i < n && isDigit(str[i])) {
            int digit = str[i] - '0';
            if (num > maxDiv10 || (num == maxDiv10 && digit >= 8)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            num = num * 10 + digit;
            i++;
        }
        return sign * num;
    }
};