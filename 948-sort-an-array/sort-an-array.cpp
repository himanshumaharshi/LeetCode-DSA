class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty())
            return nums;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        // Create a count array to store the count of each unique object
        vector<int> count(maxVal - minVal + 1, 0);

        // This is to Store the count of each element in count array
        for (int num : nums) {
            count[num - minVal]++;
        }

        // This is to Over write the input array;
        int index = 0;
        for (int i = 0; i < count.size(); i++) {
            while (count[i] > 0) {
                nums[index++] = i + minVal;
                count[i]--;
            }
        }

        return nums;
    }
};