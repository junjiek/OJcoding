#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = (int)s.size();
        int maxLen = 0;
        int* pos = new int[256];
        for (int k = 0; k < 256; k++)
            pos[k] = -1;
        while (j < n) {
            if (pos[s[j]] >= i) {
                if (j - i > maxLen)
                    maxLen = j - i;
                i = pos[s[j]] + 1;
            }
            pos[s[j]] = j;
            j ++;
        }
        delete [] pos;
        return max(j - i, maxLen);
    }
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int* cnt = new int[256];
        for (int i = 0; i < 256; i++) {
            cnt[i] = 0;
        }
        int i = 0, n = (int)s.size();
        int numDistinct = 0;
        int maxLen = 0;
        for (int j = 0; j < n; j++) {
            if (cnt[s[j]] == 0)
                numDistinct ++;
            cnt[s[j]]++;
            while (numDistinct > 2) {
                cnt[s[i]] --;
                if (cnt[s[i]] == 0)
                    numDistinct --;
                i++;
            }
            maxLen = max(j - i + 1, maxLen);
        }
        return maxLen;
    }
};

int main() {
    string str = "asjrgapa";
    Solution s;
    cout << s.lengthOfLongestSubstring(str);

    return 0;

}