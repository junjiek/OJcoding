class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = (int)s.size() - 1;
        while (i <= j) {
            char l, r;
            while (i < (int)s.size() && !(l = isValid(s[i])))
                i ++;
            while (j >= 0 && !(r = isValid(s[j])))
                j --;
            if (i <= j && l != r)
                return false;
            i ++;
            j --;
        }
        return true;
    }
    char isValid(char c) {
        if (c <=  'Z' && c >= 'A')
            return c - 'A' + 'a';
        if (c <= 'z' && c >= 'a')
            return c;
        if (c <= '9' && c >= '0')
            return c;
        return 0;
    }
};