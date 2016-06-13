#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Solution {
    static const int values[13];
    static const string symbols[13];
public:
    string intToRoman(int num) {
        string roman = "";
        int i = 0;
        while (num > 0) {
            int k = num / values[i];
            for (int j = 0; j < k; j++) {
                for (int p = 0; p < symbols[i].size(); p++)
                    roman.push_back(symbols[i][p]);
                num -= values[i];
            }
            i++;
        }
       return roman;
    }
};

const int Solution::values[13] = {
        1000, 900, 500, 400,
        100,  90,  50,  40,
        10,   9,   5,   4,
        1};
const string Solution::symbols[] = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV",
        "I" };


int main() {
    Solution s;
    return 0;
}