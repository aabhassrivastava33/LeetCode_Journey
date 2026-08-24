#include <vector>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        
        for (int left = 0; left < n; left++) {
            int current_sum = 0;
            for (int right = left; right < n; right++) {
                current_sum += nums[right];
                
                if (current_sum == k) {
                    count++;
                }
            }
        }
        
        return count;
    }
};