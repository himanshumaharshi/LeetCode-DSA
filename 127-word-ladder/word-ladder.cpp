class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());

        // remove word from set (wordList) which we have inserted in queue
        st.erase(beginWord);

        while (!q.empty()) {
            pair<string, int> frontNode = q.front();
            q.pop();

            string currString = frontNode.first;
            int currCount = frontNode.second;

            // check are we reached destination or not
            if (currString == endWord) {
                return currCount;
            }

            for (int index = 0; index < currString.length(); index++) {
                // replace value present at currString[index] with 'a' to 'z'
                char orgChar = currString[index];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    currString[index] = ch;
                    // check in word list
                    if (st.find(currString) != st.end()) {
                        q.push({currString, currCount + 1});
                        st.erase(currString);
                    }
                }
                // bring back the currString to its original state
                currString[index] = orgChar;
            }
        }
        return 0;
    }
};