class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int score = 0;
        int maxScore = 0;
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            if (power >= tokens[start]) {
                power -= tokens[start++];
                score++;
                maxScore = max(maxScore, score);
            }
            else if (score > 0 && power < tokens[start]) {
                power += tokens[end];
                score--;
                end--;
            }
            else
                break;
        }
        return maxScore;
    }
};