class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int product = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                maxProduct = max(maxProduct, product);
                product *= nums[j];
            }
            maxProduct = max(maxProduct, product);
        }
        return maxProduct;
    }
};