class Solution {
public:
    int findPeakIndex(vector<int> arr){
        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e - s) / 2;
        while(s < e){
            if(arr[mid] < arr[mid + 1])
            {
                // search in right
                s = mid + 1;
            }
            else
            {
                // search in left
                e = mid;
            }
            // update mid
            mid = s + (e - s) / 2;
        }
        return s;
    }

    int peakIndexInMountainArray(vector<int>& arr) {
        return findPeakIndex(arr);
    }
};