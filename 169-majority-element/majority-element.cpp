class Solution {
public:
    // naive approach (brute force)
    int bruteForce(vector<int>& nums, int n) {
        for (int i = 0; i < nums.size(); i++) {
            int freq = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    freq++;
                }
            }
            if (freq > n / 2) {
                return nums[i];
            }
        }
        return -1;
    }

    //  better approach from brute force using hashmaps
    int solveUsingHashmap(vector<int>& nums, int n) {
        map<int, int> mp;
        // store the frequency of all the elements in the map
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        // now find the element with frequency > n / 2
        for (auto ele: mp) {
            if (ele.second > n / 2) 
                return ele.first;
        }
        return -1;
    }
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        //  brute force T.C = O(2N)
        // int ansBruteForce = bruteForce(nums, n);

        // optimised approach T.C = O(N)
        int ansOptimised = solveUsingHashmap(nums, n);
        return ansOptimised;
    }
};