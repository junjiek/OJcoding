#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // O(n^2) time, O(n^2) space
    // string longestPalindrome(string s) {
    //     int n = (int)s.size();
    //     bool* P = new bool[n*n];
    //     for (int i = 0; i < n*n; i++)
    //         P[i] = false;
    //     int maxLen = 1;
    //     int maxi = 0;
    //     for(int i = 0; i < n; i++) {
    //         P[i * n + i] = true;
    //         if (i < n - 1 && s[i] == s[i + 1]) {
    //             maxLen = 2;
    //             maxi = i;
    //             P[i * n + i + 1] = true;
    //         }
    //     }
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i+2; j < n; j++) {
    //             P[i * n + j] = (s[i] == s[j]) && P[(i + 1) * n + j - 1];
    //             if (P[i * n + j] && j - i + 1 > maxLen) {
    //                 maxLen = j - i + 1;
    //                 maxi = i;
    //             }
    //         }
    //     }
    //     return s.substr(maxi, maxLen);
    // }
    string longestPalindrome(string s) {
        int maxLen = 0, start = 0;
        int n = (int)s.size();
        for (int i = 0; i < n; i++) {
            int l1, l2 = 0;
            l1 = expandAroundCenter(s, i, i);
            l2 = (i < n - 1) ? expandAroundCenter(s, i, i + 1) : 0;
            int len = max(l1, l2);
            if (len > maxLen) {
                maxLen = len;
                start = (i - (len - 1)/ 2);
            }

        }
        return s.substr(start, maxLen);
    }
    int expandAroundCenter(string& s, int left, int right) {
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            left --;
            right ++;
        }
        return right - left -1;
    }
};

// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
 
string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)
    
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;
 
    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }
 
  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
  delete[] P;
  
  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}


int main() {
    string s = "abbac";
    Solution solu;
    cout << solu.longestPalindrome(s) << endl;
}