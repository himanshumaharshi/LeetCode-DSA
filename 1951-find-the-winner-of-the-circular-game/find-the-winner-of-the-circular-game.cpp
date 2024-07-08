class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; i++)
            q.push(i); // push 1 -> n elements in queue

        // run until queue is left with single digit which is our answer
        while (q.size() != 1) {
            int count = 1;
            while (count < k) {
                // run until count = k - 1, so after this queue.front() will be kth element which has to be removed
                int ele = q.front();
                q.pop();
                q.push(ele);
                count++;
            }
            q.pop(); // remove the last friend
        }
        return q.front();
    }
};