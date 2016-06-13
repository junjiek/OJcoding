#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;
class Solution {
    unordered_map<char, char> m;
public:
    Solution() {
        m[']'] = '[';
        m[')'] = '(';
        m['}'] = '{';
    }
    bool isValid(string s) {
        std::stack<char> st;
        for (int i = 0; i < (int)s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                st.push(s[i]);
            } else {
                if (st.empty() || st.top() != m[s[i]])
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
int main() {
    Solution s;
    cout << s.isValid("{");
    return 0;
}