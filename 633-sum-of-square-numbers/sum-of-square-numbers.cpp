class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);
        while (left <= right) {
            long long squareSum = pow(left, 2) + pow(right, 2);
            if (squareSum == c) {
                return true;
            } else if (squareSum > c) {
                right--;
            } else {
                left++;
            }
        }
        return false;
    }
};