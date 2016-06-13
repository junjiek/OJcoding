#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <Stack>
#include <sstream>
using namespace std;

class Solution {
    int string2int(string s) {
        stringstream ss;
        int i;
        ss << s;
        ss >> i;
        return i;
    }
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
        for (int i = 0; i < (int)tokens.size(); i++) {
            char c = tokens[i][0];
            if (tokens[i].size() > 1 || (c >= '0' && c <= '9')) {
                s.push(string2int(tokens[i]));
                continue;
            }
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            // cout << op1 << " " << op2 << endl;
            switch (c) {
                case '+': s.push(op1 + op2); break;
                case '-': s.push(op1 - op2); break;
                case '*': s.push(op1 * op2); break;
                case '/': s.push(op1 / op2); break;
            };
        }
        return s.top();
    }
};

int main() {
    std::vector<string> v;
    v.push_back("3");
    v.push_back("-4");
    v.push_back("+");
    Solution s;
    s.evalRPN(v);
    return 0;
}
