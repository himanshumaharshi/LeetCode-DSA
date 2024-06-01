class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        int i = 0;
        int j = i + 1;
        while (j < s.length()) {
            score += abs(s[i++] - s[j++]);
        }
        return score;
    }
};