class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // Initialize a hashmap map to store the cumulative count of 0s and 1s encountered along with their respective indices.
        unordered_map<int, int> map;
        // track the cumulative count of 0s and 1s encountered
        int count = 0;
        // store the length of the longest contiguous subarray with an equal number of 0s and 1s
        int ans = 0;
        // Put an initial entry into the map with key 0 and value -1. This indicates that when no elements are encountered, the count of 0s and 1s is 0
        map[0] = -1;

        // For each element nums[i], if it's equal to 1, increment the count by 1; otherwise, decrement count by 1
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                count++;
            } else {
                count--;
            }

            // Check if the map contains the current value of count
            if(map.find(count) != map.end()) {
                // update ans by taking the maximum of the current value of ans and the difference between the current index i and the index stored in the map for the current count
                ans = std::max(ans, i - map[count]);
            } else {
                // insert a new entry into the map with the current count as the key and the current index i as the value
                map[count] = i;
            }
        }
        return ans;
    }
};