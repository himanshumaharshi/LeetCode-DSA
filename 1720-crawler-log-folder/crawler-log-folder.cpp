class Solution {
public:
    int minOperations(vector<string>& logs) {
        int operations = 0;
        for (int i = 0; i < logs.size(); ++i) {
            string str = logs[i];
            if (str == "../" && operations >= 0) {
                if (operations == 0)
                    continue;
                operations--;
            }
            else if (str == "./")
                continue;
            else {
                operations++;
            }
        }
        return operations;
    }
};