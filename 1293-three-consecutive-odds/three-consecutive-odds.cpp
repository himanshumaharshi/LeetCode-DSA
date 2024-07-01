class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i = 0;
        int j = 2;
        while (j < arr.size()) {
            int count = 0;
            for (int k = i; k <= j; k++) {
                if (arr[k] % 2 != 0) {
                    count++;
                }
            }
            if (count == 3) {
                return true;
            }
            i++;
            j++;
        }
        return false;
    }
};