#include <vector>
#include <algorithm>

class Solution {
public:
    bool ispossible(vector<int> &nums, int mid, int threshold)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int val = nums[i] / mid;
            if (nums[i] % mid != 0)
            {
                val++; // Hand-rolled ceiling division logic
            }
            
            sum += val;
            
            if (sum > threshold)
            {
                return false;
            }
        }
        return true;
    }

    int smallestDivisor(vector<int> &nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = end;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (ispossible(nums, mid, threshold))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};