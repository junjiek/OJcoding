#include <iostream>
#include <string>
using namespace std;

class Solution {
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
public:
    // bool isExpNumber(string s) {
    //     int i = 0;
    //     if (s[i] == '+' || s[i] == '-')
    //         i++;
    //     int n = (int)s.size();
    //     bool hasDigit = false;
    //     while (i < n) {
    //         if (isDigit(s[i])) {
    //             i++;
    //             hasDigit = true;
    //         } else {
    //             return false;
    //         }
    //     }
    //     return hasDigit;
    // }
    // bool isNumber(string s) {
    //     int i = 0;
    //     int n = (int)s.size();
    //     while(i < n && s[i] == ' ')
    //         i++;
    //     if (s[i] == '+' || s[i] == '-')
    //         i++;
    //     int j = n - 1;
    //     while(j >= 0 && s[j] == ' ')
    //         j--;
    //     bool hasDecimal = false;
    //     bool exponential = false;
    //     bool hasDigit = false;
    //     while (i <= j) {
    //         if (isDigit(s[i])) {
    //             i++;
    //             hasDigit = true;
    //         } else if (s[i] == '.' && !hasDecimal && !exponential) {
    //             hasDecimal = true;
    //             i++;
    //         } else if (s[i] == 'e' && hasDigit && !exponential) {
    //             exponential = true;
    //             return isExpNumber(s.substr(i + 1, j - i));
    //         } else {
    //             return false;
    //         }
    //     }
    //     return hasDigit;
        
    // }
    bool isNumber(string s) {
        int i = 0, n = (int)s.size();
        while (i < n && s[i] == ' ') i++;
        if (s[i] == '+' || s[i] == '-') i++;
        bool isNumeric = false;
        while (i < n && isDigit(s[i])) {
            i++;
            isNumeric = true;
        }
        if (i < n && s[i] == '.') {
            i++;
            while (i < n && isDigit(s[i])) {
                i ++;
                isNumeric = true;
            }
        }
        if (isNumeric && i < n && s[i] == 'e') {
            i ++;
            isNumeric = false;
            if (i < n && (s[i] == '+' || s[i] == '-')) i ++;
            while (i < n && isDigit(s[i])) {
                i ++;
                isNumeric = true;
            }
        }
        while (i < n && s[i] == ' ') i++;
        return isNumeric && i == n;
    }
};

int main() {
    Solution s;
    string str = "1e0";
    cout << s.isNumber(str) << endl;
    return 0;
}