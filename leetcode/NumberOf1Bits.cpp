#include <iostream>

using namespace std;


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int k = sizeof(n)*8;
        uint32_t mask = 1;
        int  count = 0;
        for (int i=0; i<k; i++){
            if(mask & n) count ++;
            mask <<= 1;
        }
        return count;
    }
};

int main() 
{
    uint32_t test = 16;
    Solution solution;
    cout << solution.hammingWeight(test) << endl;
}