class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // map to keep track of the frequencies of different odd counts
        unordered_map<int, int> oddCountTrack;

        int ans = 0;
        int oddCount = 0;
        oddCountTrack[oddCount] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            // Increment the odd count if the current element is odd 
            oddCount += (nums[i] % 2 == 0) ? 0 : 1;
            // Check if there is a previous odd count 'k' such that oddCount - k has been encountered before
            if (oddCountTrack.count(oddCount - k)) {
                // If found, update the answer by adding the frequency of that odd count to the result
                ans += oddCountTrack[oddCount - k];
            }
            // update oddCount frequency of the current odd count
            oddCountTrack[oddCount]++;
        }
        return ans;
    }
};