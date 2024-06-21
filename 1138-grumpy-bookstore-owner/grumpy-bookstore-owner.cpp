class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int unsatisfied = 0;
        // initially get the number of unsatisfied customers from the first window of size minutes
        for (int i = 0; i < minutes; ++i) {
            unsatisfied += customers[i] * grumpy[i];
            // here grupmy array contains only binary, so customer  will only be added if
            // it is multiplied by 1 which is the grumpy state, or we can also use if-else
        }
        // now calculate the maximum number of unsatisfied customers using grumpy array
        // starting from minutes as we have already calculated first window unsatisfied customers
        int maxUnsatisfied = unsatisfied;
        int left = 0;
        int right = minutes;
        while (right < customers.size()) {
            // add unsatisfied customer from current new minute
            unsatisfied += customers[right] * grumpy[right];
            // remove previously added customer which is out of window
            unsatisfied -= customers[left] * grumpy[left];
            // store the max number of unsatisfied customer
            maxUnsatisfied = max(maxUnsatisfied, unsatisfied);

            // slide window
            left++;
            right++;
        }
        // now get all satfisfied customer count
        int satisfied = 0;
        for (int i = 0; i < customers.size(); ++i)
            if (!grumpy[i])
                satisfied += customers[i];

        // now return satisfied and max Unsatisfied as result
        return satisfied + maxUnsatisfied;
    }
};