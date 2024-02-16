class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0; // how much gas is less
        int balance = 0; // total balance of gas after addition
        int start = 0; // starting index

        for(int i = 0; i < gas.size(); i++)
        {
            balance += gas[i] - cost[i];
            if(balance < 0)
            {
                deficit += balance; // spetial attention
                start = i + 1;
                balance = 0;
            }
        }

        if(deficit + balance >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};