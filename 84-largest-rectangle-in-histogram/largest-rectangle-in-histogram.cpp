class Solution {
public:
    vector<int> prevSmallerElement(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            int curr = heights[i];
            while (s.top() != -1 && heights[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            // push the index in stack
            s.push(i);
        }
        return ans;
    }
    vector<int> nextSmallerElement(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(heights.size());
        for (int i = heights.size() - 1; i >= 0; i--) {
            int curr = heights[i];
            while (s.top() != -1 && heights[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            // push the index in stack
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        // get the previous smaller element from array
        vector<int> prevSmaller = prevSmallerElement(heights);

        // get the next smaller element from array
        vector<int> nextSmaller = nextSmallerElement(heights);

        // find maximum
        int size = heights.size();
        int maxArea = INT_MIN;
        for (int i = 0; i < heights.size(); i++) {
            int length = heights[i];
            if (nextSmaller[i] == -1) {
                nextSmaller[i] = size;
            }
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            int area = length * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};