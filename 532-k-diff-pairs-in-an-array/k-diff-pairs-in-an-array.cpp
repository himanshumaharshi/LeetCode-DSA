class Solution {
public:

    int binarySearch(vector<int> & arr, int s, int k)
    {
        int e = arr.size() - 1;
        while(s <= e)
        {
            int mid = s + (e - s) / 2;
            if(arr[mid] == k)
            {
                return mid;
            }
            else if(arr[mid] > k)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return - 1;
    }

    int findPairs(vector<int>& arr, int k) {
        // using binary search
        sort(arr.begin(), arr.end());
        set<pair<int, int>> ans;
        for(int i = 0; i < arr.size(); i++)
        {
            if(binarySearch(arr, i + 1, arr[i] + k) != -1)
            {
                ans.insert({arr[i], arr[i] + k});
            }
        }
        return ans.size();
    }
};