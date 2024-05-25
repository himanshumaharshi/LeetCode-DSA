class Solution {
public:
    void recursiveBacktrack(string s, vector<string>& wordDict,
                            unordered_set<string>& wordSet,
                            vector<string>& result, string& currWord,
                            int startIndex) {
        // base case
        if (startIndex == s.length()) {
            result.push_back(currWord);
            return;
        }

        for (int endIndex = startIndex + 1; endIndex <= s.length();
             endIndex++) {
            // get words between starting index and ending index
            string word = s.substr(startIndex, endIndex - startIndex);
            // check if the word is present in set or not
            if (wordSet.find(word) != wordSet.end()) {
                string orgWord = currWord;
                if (!currWord.empty()) {
                    currWord += " ";
                }
                currWord += word;
                // recursive call
                recursiveBacktrack(s, wordDict, wordSet, result, currWord, endIndex);
                // backtrack
                currWord = orgWord;
            }
        }
    }

    vector<string> dpTopDown(const string& s, const unordered_set<string>& wordSet, unordered_map<string, vector<string>>& dp) {
        // check if the subString is already present is dp or not
        if (dp.count(s)) {
            return dp[s];
        }
        // base case
        if (s.empty()) {
            return {""};
        }
        vector<string> result;
        for (int i = 1; i <= s.length(); i++) {
            string currWord = s.substr(0, i);
            // if currWord is a valid word
            if (wordSet.count(currWord)) {
                for (const string& nextWord: dpTopDown(s.substr(i), wordSet, dp)) {
                    // append curr word and next word with space in between
                    // if next word exists
                    result.push_back(currWord + (nextWord.empty() ? "" : " ") + nextWord);
                }
            }
        }
        // store result for curr substring
        dp[s] = result;
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> result;
        string currWord;
        int index = 0;

        // using recursion and backtracking {T.C -> O(n^2), S.C -> O(n^2)}
        // recursiveBacktrack(s, wordDict, wordSet, result, currWord, index);

        // using dynamic programming topdown approach {T.C -> O(n^2), S.C -> O(n^2)}
        unordered_map<string, vector<string>> dp;
        result = dpTopDown(s, wordSet, dp);
        return result;
    }
};