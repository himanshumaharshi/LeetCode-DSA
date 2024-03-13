class Solution {
public:
    int pivotInteger(int n) {
        int start = 1;
        int end = n;
        while (start <= end) {
            // find middle element
            int mid = (start + end) / 2;
            // calculate the sum of left elements
            int leftSum = (mid * (mid + 1)) / 2;
            // calculate the sum of right elements
            int rightSum = ((n * (n + 1)) / 2) - (((mid - 1) * (mid)) / 2);
            // if both sums are equal than mid is the pivot integer else update the value of start and end pointer according to there value
            if (leftSum == rightSum) {
                return mid;
            }
            else if (leftSum < rightSum) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }

        }
        return -1;
    }
};