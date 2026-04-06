class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If mid element is greater than right,
            // minimum is in right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // Otherwise minimum is in left half (including mid)
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};