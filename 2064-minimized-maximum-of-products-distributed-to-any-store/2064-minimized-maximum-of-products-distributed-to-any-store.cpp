#include <vector>
#include <algorithm>

class Solution {
private:
    bool canDistribute(int x, int n, const std::vector<int>& quantities) {
        int storesNeeded = 0;
        for (int q : quantities) {
            // Equivalent to ceil(q / x)
            storesNeeded += (q + x - 1) / x;
            if (storesNeeded > n) return false; // Early exit
        }
        return storesNeeded <= n;
    }

public:
    int minimizedMaximum(int n, std::vector<int>& quantities) {
        int left = 1;
        int right = *std::max_element(quantities.begin(), quantities.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(mid, n, quantities)) {
                ans = mid;
                right = mid - 1; // Try to find a smaller valid maximum
            } else {
                left = mid + 1;  // Increase the limit
            }
        }

        return ans;
    }
};