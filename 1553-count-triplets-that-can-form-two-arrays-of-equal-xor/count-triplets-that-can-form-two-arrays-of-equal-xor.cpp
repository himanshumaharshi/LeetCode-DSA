class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixXOR(arr.begin(), arr.end());
        prefixXOR.insert(prefixXOR.begin(), 0);
        int size = prefixXOR.size();
        int count = 0;

        // Performing XOR operation on the array elements
        for (int i = 1; i < size; ++i)
            prefixXOR[i] ^= prefixXOR[i - 1];

        // Maps to store counts and totals of XOR values encountered
        unordered_map<int, int> countMap, totalMap;

        // Iterating through the array
        for (int i = 0; i < size; ++i) {
            // Calculating contribution of current element to the result
            count +=
                countMap[prefixXOR[i]]++ * (i - 1) - totalMap[prefixXOR[i]];

            // Updating total count of current XOR value
            totalMap[prefixXOR[i]] += i;
        }

        return count;
    }
};