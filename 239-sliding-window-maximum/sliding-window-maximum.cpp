class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // store indexes in deque not actual numbers
        deque<int> dq;
        vector<int> ans;

        // first window
        for(int i = 0; i < k; i++)
        {
            // remove small elements
            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            // inserting index, so that we can check window element
            dq.push_back(i);
        }

        // store answer for first window
        ans.push_back(nums[dq.front()]);

        // process remaining windows
        for(int i = k; i < nums.size(); i++)
        {
            // remove out of window elemets
            if(!dq.empty() && i - k >= dq.front())
            {
                dq.pop_front();
            }
            
            // remove small element for current element
            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            // inserting index, so that we can checkout window element
            dq.push_back(i);

            // store ans of current window
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};