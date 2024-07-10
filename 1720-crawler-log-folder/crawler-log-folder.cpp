class Solution {
public:
    int minOperations(vector<string>& logs) {
        int operations = 0;
        for (int i = 0; i < logs.size(); ++i) {
            string str = logs[i];
            if (str == "../")
                operations = max(0, operations - 1);
            else if (str == "./")
                continue;
            else {
                operations++;
            }
        }
        return operations;
    }
};