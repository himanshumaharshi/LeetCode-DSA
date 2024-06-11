class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // store frequency of all elements of arr1
        map<int, int> mp;
        for (int ele : arr1) {
            mp[ele]++;
        }
        // ans array to store ans
        vector<int> ans;
        for (int i = 0; i < arr2.size(); i++) {
            // get frequency of every element of arr2 accouding to arr1
            // until frequency != 0 add arr2 element to ans array and decrese
            // the freq in map
            while (mp[arr2[i]] != 0) {
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        // add remaining element which are unique in arr1 to ans array
        for (auto ele : mp) {
            if (ele.second != 0) {
                while (ele.second != 0) {
                    ans.push_back(ele.first);
                    ele.second--;
                }
            }
        }
        return ans;
    }
};