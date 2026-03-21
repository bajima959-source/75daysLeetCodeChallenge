class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0; // pointer for the position of non-zero elements

        // Move non-zero elements forward
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }

        // Fill remaining positions with zeros
        while (index < nums.size()) {
            nums[index++] = 0;
        }
    }
};