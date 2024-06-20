class Solution {
public:
    bool possibleToPlace(int mid, vector<int>& position, int m) {
        int prevPosition = position[0];
        // keep track of placed balls
        int countBalls = 1;
        // start loop form position[1] as position[0] is already stored in prevPosition
        for (int i = 1; i < position.size(); ++i) {
            int currPosition = position[i];
            if (currPosition - prevPosition >= mid) {
                // if the difference between curr and prev ball is >= mid
                // only then place the ball
                countBalls++;
                prevPosition = currPosition;
            }
            // if all balls are placed then break the loop
            if (countBalls == m)
                break;
        }

        // return true if all balls are placed else return false
        return countBalls == m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int minForce = 1;
        int maxForce = position[position.size() - 1] - position[0];
        int ans = 0;
        while (minForce <= maxForce) {
            int mid = minForce + (maxForce - minForce) / 2;
            // binary search which search in range of minEle to maxEle - minEle
            if (possibleToPlace(mid, position, m)) {
                // means that all balls are possible to be
                // placed according to mid value then
                // search for much higher value by placing minForce = mid + 1
                ans = mid;
                minForce = mid + 1;
            }
            else {
                // means the value of mid is high and all balls cannot be placed
                maxForce = mid - 1;
            }
        }
        return ans;
    }
};