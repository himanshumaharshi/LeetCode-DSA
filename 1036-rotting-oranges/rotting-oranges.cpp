class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue < pair<pair<int, int>, int>> q;
        vector<vector<int>> arr = grid;
        int ansTime = 0;

        // insert all rotten oranges in queue
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 2) {
                    // rotten oranges found
                    pair<int, int> coordinates = make_pair(row, col);
                    q.push({coordinates, 0});
                }
            }
        }

        while (!q.empty()) {
            auto frontNode = q.front();
            q.pop();
            int x = frontNode.first.first;
            int y = frontNode.first.second;
            int time = frontNode.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < arr.size() && newY >= 0 &&
                    newY < arr[0].size() && arr[newX][newY] == 1) {
                    pair<int, int> newCoordinates = make_pair(newX, newY);
                    // update ans time
                    ansTime = max(ansTime, time + 1);

                    q.push({newCoordinates, time + 1});
                    // mark rotten
                    arr[newX][newY] = 2;
                }
            }
        }

        // check for any left fresh oranges
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[0].size(); j++) {
                if (arr[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ansTime;
    }
};