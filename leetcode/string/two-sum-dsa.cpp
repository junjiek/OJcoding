#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


// O(n) runtime; O(1) find; O(n^2) space
class TwoSumDS {
    vector<int> keys;
    unordered_set<int> sums;
public:
    void add(int key) {
        for (int i = 0; i < (int)keys.size(); i++) {
            sums.insert(keys[i] + key);
        }
        keys.push_back(key);
    }
    bool find(int target) {
        return sums.find(target) != sums.end();
    }
};

// O(1) runtime; O(n) find; O(n) space
// 需要特殊处理有重复元素的情况！！！
class TwoSumDS {
    unordered_map<int, int> key_cnt_m;
public:
    void add(int key) {
        if (key_cnt_m.find(key) == key_cnt_m.end())
            key_cnt_m[key] = 1;
        else
            key_cnt_m[key] ++;
    }
    bool find(int target) {
        for (auto& k : keys) {
            int com = target - k;
            if (com == k)
                return key_cnt_m[com] > 1;
            else if (keys.find(com) != keys.end()) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    TwoSumDS c;
    c.add(1);
    c.add(3);
    c.add(5);
    cout << c.find(4) << endl;
    cout << c.find(7) << endl;
    return 0;
}