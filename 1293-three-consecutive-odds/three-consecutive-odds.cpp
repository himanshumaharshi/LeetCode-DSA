class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        // Loop through the array up to the third-to-last element
        for (int i = 2; i < arr.size(); i++)
            // Check if the product is odd
            if (arr[i - 2] * arr[i - 1] * arr[i] % 2 == 1) return true;
        
        return false;
    }
};