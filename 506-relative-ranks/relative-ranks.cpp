class Solution {
public:
    int findMax(vector<int>& score) {
        int maxScore = 0;
        for (int s : score) {
            if (s > maxScore) {
                maxScore = s;
            }
        }
        return maxScore;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        // Add the original index of each score to the array
        // Where the score is the key
        int maxScore = findMax(score);
        vector<int> scoreToIndex(maxScore + 1, 0);
        for (int i = 0; i < n; i++) {
            scoreToIndex[score[i]] = i + 1;
        }

        const vector<string> MEDALS = {"Gold Medal", "Silver Medal",
                                       "Bronze Medal"};

        vector<string> rank(n);
        int place = 1;
        for (int i = maxScore; i >= 0; i--) {
            if (scoreToIndex[i] != 0) {
                int originalIndex = scoreToIndex[i] - 1;
                if (place < 4) {
                    rank[originalIndex] = MEDALS[place - 1];
                } else {
                    rank[originalIndex] = to_string(place);
                }
                place++;
            }
        }

        return rank;
    }
};