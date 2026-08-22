class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Minimum is in the right unsorted portion
                left = mid + 1;
            } else {
                // Minimum is at mid or to its left
                right = mid;
            }
        }

        // Loop terminates when left == right, pointing to the minimum element
        return nums[left];
    }
};