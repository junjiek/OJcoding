#include <iostream>
#include <string>

using namespace std;

// RabinKarp
class Solution {
    static const long M = 1000000000000000003L;
    static const int R = 31;
    long patternHash;
    long RK;
    int K;
    void RabinKarp(const string& pattern) {
        K = (int)pattern.size();
        patternHash = hash(pattern);
        RK = 1;
        for (int i = 0;i < K; i++) {
            RK = (RK * R) % M;
        }
    }
    long hash(const string& s) {
        long h = 0;
        for (int i = 0; i < (int)s.size(); i++){
            h = (h * R + s[i]) % M;
        }
        return h;
    }
    
public:
    int strStr(string haystack, string needle) {
        if (!needle.size())
            return 0;
        RabinKarp(needle);
        long substrHash = 0;
        substrHash = hash(haystack.substr(0, K));
        for (int i = 0; i < (int)haystack.size() - K + 1; i++) {
            if (substrHash == patternHash && haystack.substr(i, K) == needle) {
                return i;
            }
            substrHash = (substrHash * R  + haystack[i + K] - haystack[i] * RK % M + M ) % M;
        }
        return -1;
    }
};

// KMP
class Solution {
    int* buildNext(string& s) {
        int* N = new int[(int)s.size()];
        int t = N[0] = -1;
        int i = 0;
        while (i < (int)s.size() - 1) {
            if (t < 0 || s[i] == s[t]) {
                i ++;
                t ++;
                N[i] = (s[i] != s[t]) ? t : N[t];
            } else {
                t = N[t];
            }
        }
        return N;
    }
public:
    int strStr(string haystack, string needle) {
        int n = (int)haystack.size();
        int m = (int)needle.size();
        if (m == 0)
            return 0;
        if (n < m)
            return -1; 
        int* next = buildNext(needle);
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (j < 0 || haystack[i] == needle[j]) {
                i ++;
                j ++;
            } else {
                j = next[j];
            }
        }
        delete [] next;
        // ****判断是否match了
        bool match = (j == m && haystack[i-1] == needle[j-1]);
        return match ? i - j : -1;
    }
};

// BM
class Solution {
    int* buildBC(const string& P) {
        int* bc = new int[256];
        for (int i = 0; i < 256; i++) {
            bc[i] = -1;
        }
        for (int i = 0; i < (int)P.size(); i++) {
            bc[P[i]] = i;
        }
        return bc;
    }
    int* buildSS(const string& P) {
        int m = (int)P.size();
        int* ss = new int[m];
        ss[m - 1] = m;
        int lo = m - 1, hi = m - 1, j = lo - 1;
        for (; j >= 0; j --) {
            if ((lo < j) && (ss[m - hi + j - 1] <= j - lo))
                ss[j] = ss[m - hi + j -1];
            else {
                hi = j;
                lo = min(lo, hi);
                while ( lo >= 0 && (P[lo] == P[m - hi + lo - 1]))
                    lo --;
                ss[j] = hi - lo;
            }
        }
        return ss;
    }
    int* buildGS(const string& P) {
        int* ss = buildSS(P);
        int m = (int)P.size();
        int* gs = new int[m];
        for (int i = 0; i < m; i++)
            gs[i] = m;
        for (int i = 0, j = m - 1; j >= 0 ; j --) {
            if (j + 1 == ss[j])
                while (i < m - j - 1) {
                    gs[i] = m - j - 1;
                    i ++;
                }
        }
        for (int j = 0; j < m - 1; j ++) {
            gs[m - ss[j] - 1] = m - j - 1;
        }
        delete[] ss;
        return gs;
    }

public:
    int strStr(string& haystack, string& needle) {
        int* bc = buildBC(needle);
        int* gs = buildGS(needle);
        int i = 0, n = (int)haystack.size(), m = (int)needle.size();
        if (m == 0)
            return 0;
        if (n < m)
            return -1;
        while (n >= i + m) {
            int j = m - 1;
            while (needle[j] == haystack[i+j]) {
                if (--j < 0)
                    break;
            }
            if (j < 0)
                break;
            else
                i += max(gs[j], j - bc[haystack[i+j]]);
        }
        delete [] gs;
        delete [] bc;
        return (n >= i + m) ? i : -1;
    }
};


int main() {
    string haystack = "mississippi";
    string needle = "issipi";
    Solution s;
    int i = s.strStr(haystack, needle);
    cout << i << endl;

}