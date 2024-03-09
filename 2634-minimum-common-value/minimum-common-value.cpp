class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        while(s <= e) {
            int mid = s + (e - s) / 2;
            if(nums[mid] == target) {
                return true;
            }
            else if (nums[mid] > target) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return false;
    }
    
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        for(int i = 0; i < n; i++) {
            if(search(nums2, nums1[i])) {
                return nums1[i];
            }
        }
        return -1;
    }
};