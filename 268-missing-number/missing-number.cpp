class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int sum = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
        }
        int size = arr.size();
        int totalSum = size * (size + 1) / 2;
        int missing = totalSum - sum;
        return missing;
    }
        
};