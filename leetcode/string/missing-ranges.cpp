#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string int2string(int i) {
    stringstream ss;
    ss << i;
    string s;
    ss >> s;
    return s;
}

string getRange(int start, int end) {
    if (start == end) return int2string(start);
    return int2string(start) + "->" + int2string(end);
}

vector<string> findMissingRanges(int vals[], int len, int start, int end) {
    int prev = start - 1;
    vector<string> ranges;
    for (int i = 0; i <= len; ++i) {
        int cur = (i == len) ? end + 1 : vals[i];
        if (cur - prev >= 2) {
            ranges.push_back(getRange(prev + 1, cur - 1));
        }
        prev = cur;
    }
    return ranges;
}


int main() {
    int a[] = {0, 1, 3, 50, 75};
    vector<string> ans = findMissingRanges(a, 5, 0, 99);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}