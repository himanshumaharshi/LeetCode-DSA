class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        
        // invalid case
        if (len1 < len2) {
            return "";
        }
        
        int start = 0;
        int end = 0;
        int ansIndex = -1;
        int ansLen = INT_MAX;
        
        unordered_map<char, int> strMap;
        unordered_map<char, int> patternMap;
        
        // keep track of all characters of string p
        for (int i = 0; i < t.length(); i++) {
            char ch = t[i];
            patternMap[ch]++;
        }
        
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            strMap[ch]++;
            
            // valid character -> character which exists inside out pattern
            if (strMap[ch] <= patternMap[ch]) {
                count++;
            }
            
            if (count == len2) {
                // one valid window is ready
                
                // now minimize the window -> decrease frequency, update answer, move forward start
                while (strMap[s[start]] > patternMap[s[start]] || patternMap[s[start]] == 0) {
                    if (strMap[s[start]] > patternMap[s[start]]) {
                        strMap[s[start]]--;
                    }
                    start++;
                }
                
                // update answer
                int lengthOfWindow = i - start + 1;
                if (lengthOfWindow < ansLen) {
                    ansLen = lengthOfWindow;
                    ansIndex = start;
                }
            }
        }
        if (ansIndex == -1)
            return "";
        else
            return s.substr(ansIndex, ansLen);
    }
};