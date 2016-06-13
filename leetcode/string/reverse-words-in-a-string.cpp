#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        istringstream ss(s);
        string s1;
        vector<string> v;
        while (ss >> s1) {
            v.push_back(s1);
        }
        s = v.empty() ? "" : v[(int)v.size() - 1];
        for (int i = (int)v.size() - 2; i >= 0; i--)
            s += " " + v[i];
        cout << s << endl;
    }
};

class Solution {
public:
    void reverseWords(string &s) {
        int hi = (int)s.size();
        string s1 = "";
        for (int lo = (int)s.size() - 1; lo >= 0; --lo) {
            if (s[lo] == ' ')
                hi = lo;
            else if (lo == 0 || s[lo - 1] == ' ') {
                if (s1.size())
                    s1 += " ";
                s1 += s.substr(lo, hi - lo);
            }
        }
        s = s1;
    }
};

class Solution {
    void reverseWord(string& s, int lo, int hi) {
        while (lo < hi) {
            swap(s[lo++], s[--hi]);
        }
    }
public:
    void reverseWords(string &s) {
        reverseWord(s, 0, s.size());
        int lo = 0;
        for (int hi = 0; hi <= (int)s.size(); hi++) {
            if (hi == (int)s.size() || s[hi] == ' ') {
                reverseWord(s, lo, hi);
                lo = hi + 1;
            }

        }
    }
};

void reverse(vector<int>& v, int lo, int hi) {
    while (lo < hi) {
        swap(v[lo++], v[--hi]);
    }
}

void printVector(const vector<int>& v) {
    for (auto& i : v)
        cout << i << " ";
    cout << endl;
}
void rotate(vector<int>& v, int k) {
    reverse(v, 0, v.size());
    reverse(v, 0, k);
    reverse(v, k, v.size());
    printVector(v);

}


int main() {
    string str = "the sky is blue";
    Solution s;
    s.reverseWords(str);
    cout << str << endl;

    std::vector<int> v;
    for (int i = 0; i < 7; i ++)
        v.push_back(i);
    rotate(v, 3);
}