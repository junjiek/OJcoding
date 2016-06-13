class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = (int)nums.size();
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (nums[mi] < target)
                lo = mi + 1;
            else
                hi = mi;
        }
        return lo;
    }
};