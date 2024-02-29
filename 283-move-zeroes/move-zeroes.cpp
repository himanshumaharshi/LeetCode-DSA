class Solution {
public:
    // Brute force approach (worst case)
    // void moveZeroes(vector<int>& nums) {
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             if (nums[i] == 0)
    //             swap(nums[i], nums[j]);
    //         }
    //     }
    // }

    // optimal approach
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                nums[j++] = nums[i];
        }
        for (; j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};