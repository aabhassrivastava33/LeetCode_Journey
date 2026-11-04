class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        // Step 1: Mark visited indices by negating the value at that index
        for (int i = 0; i < nums.size(); ++i) {
            int index = std::abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        // Step 2: Indices with positive values correspond to missing numbers
        std::vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};