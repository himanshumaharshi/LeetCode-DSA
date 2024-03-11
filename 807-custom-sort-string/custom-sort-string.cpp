class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> charCount;
        for (auto ch: order) {
            charCount[ch] = 0;
        }
        for (auto ch: s) {
            if (charCount.find(ch) != charCount.end()) {
                charCount[ch]++;
            }
        }
        string ansString;
        for (auto ch: order) {
            ansString.append(charCount[ch], ch);
        }
        for (auto ch: s) {
            if (charCount.find(ch) == charCount.end()) {
                ansString.push_back(ch);
            }
        }
        return ansString;
    }
};