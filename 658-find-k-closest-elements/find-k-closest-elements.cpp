class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int n) {
        int s = 0;
        int e = arr.size() - 1;
        vector<int> ans;
        while ((e - s) >= k)
        {
            if (arr[e] - n == n - arr[s])
            {
                if(arr[s] < arr[e])
                {
                    e--;
                }
                else
                {
                    s++;
                }
            }
            else if (n - arr[s] > arr[e] - n)
            {
                s++;
            }
            else
            {
                //(n - arr[s] < arr[e] - n))
                e--;
            }
        }
        for(int i = s; i <= e; i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};