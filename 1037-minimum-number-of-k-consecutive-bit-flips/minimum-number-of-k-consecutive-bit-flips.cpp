class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        // Deque to keep track of flips within the window
        deque<int> flipQue;
        // Count of flips affecting the current index
        int flipCountFromPastForCurri = 0;

        for (int i = 0; i < n; i++) {
            // If the window size exceeds k, remove the oldest flip effect
            if (i >= k) {
                flipCountFromPastForCurri -= flipQue.front();
                flipQue.pop_front();
            }

            // If the current element needs to be flipped
            // (flipCountFromPastForCurri % 2 == nums[i]) implies the element is
            // '0' if flips count is even
            if (flipCountFromPastForCurri % 2 == nums[i]) {
                // If there's not enough space to flip the subarray of length k,
                // return -1
                if (i + k > n) {
                    return -1;
                }
                // Increment the flip counter and record the flip in the deque
                flipCountFromPastForCurri++;
                flipQue.push_back(1);
                // Increment the number of flips
                flips++;
            } else {
                // If no flip is needed, record a '0' in the deque
                flipQue.push_back(0);
            }
        }

        return flips;
    }
};