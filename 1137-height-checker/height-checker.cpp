class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> dummy = heights;
        sort(dummy.begin(), dummy.end());
        int len = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != dummy[i])
                len++;
        }
        return len;
    }
};