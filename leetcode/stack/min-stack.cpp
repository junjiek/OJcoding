#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <Stack>

using namespace std;
class MinStack {
    std::stack<int> st;
    std::stack<int> minSt;
public:
    void push(int x) {
        st.push(x);
        if (minSt.empty() || x <= minSt.top())
            minSt.push(x);
    }

    void pop() {
        if (st.top() == minSt.top())
            minSt.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {
    // Solution s;
    MinStack s;
    s.push(-2);
    return 0;
}