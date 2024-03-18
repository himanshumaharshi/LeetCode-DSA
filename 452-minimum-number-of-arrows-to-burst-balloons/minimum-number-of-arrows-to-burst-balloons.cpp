class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sorts the 'points' vector of vectors based on the first element of each vector in ascending order.
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        int arrows = 1;
        int end = points[0][1];

        // Iterate through the 'points' vector starting from index 1, while updating 'arrows' count and 'end' position based on the condition:
        for (size_t i = 1; i < points.size(); ++i) {
            // If the x-coordinate of the current point is greater than the 'end' position, increment 'arrows' count and update 'end' to the y-coordinate of the current point
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1];
            }
            else {
                // update 'end' to the minimum of its current value and the y-coordinate of the current point.
                end = std::min(end, points[i][1]);
            }
        }

        return arrows;
    }
};