class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        // store the frequency of each task
        for(char task : tasks){
            freq[task - 'A']++;
        }

        // Sort the 'freq' array to arrange task frequencies in ascending order
        sort(begin(freq), end(freq));

        // calculate the maximum chunk size by subtracting 1 from the highest frequency
        int chunk = freq[25] - 1;
        // calculate the idle time as the maximum chunk size multiplied by the given interval 'n'
        int idel = chunk * n;

        // Iterate through frequencies from second highest to lowest and subtracts the minimum between the current chunk size and the frequency at index 'i' from the total idle time.
        for(int i = 24; i >= 0; i--){
            idel -= min(chunk, freq[i]);
        }

        // Return the total number of tasks plus the idle time if it's non-negative, otherwise returns the original task count
        return idel < 0 ? tasks.size() : tasks.size() + idel;
    }
};