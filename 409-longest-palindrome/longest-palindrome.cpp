class Solution {
public:
    int longestPalindrome(string s) {
        // --------------- Brute Force ---------------
        // first approach is of brute force in this I have firstly stored the
        // frequency of the all characters and then if the frequency of an
        // element is even then simply add the frequency to the result and if
        // the frequency of an element is odd then add the frequency to result
        // by subtracting 1 whch means make it even and make flag to true, while
        // returning the result if the flag is true add 1 as removed earlier in
        // odd case else return the result

        // unordered_map<char, int> freq;
        // for (int i = 0; i < s.length(); i++) {
        //     freq[s[i]]++;
        // }
        // int result = 0;
        // bool hasOddFreq = false;
        // for (auto ele : freq) {
        //     int frequency = ele.second;
        //     if (frequency % 2 == 0) {
        //         result += frequency;
        //     } else {
        //         // frequency is odd
        //         result += frequency - 1;
        //         hasOddFreq = true;
        //     }
        // }
        // return hasOddFreq ? result + 1 : result;

        // ----------------- optimal -----------------
        // In this approach we will be using hash set, firstly we will add
        // characters from s and simultaneously will also check that if any
        // current character is found in hash set then remove it from hash set
        // and increment result by 2 {1 for removed character and 1 for matched
        // cahracter} after this if hash set has left with any char in itself
        // then this means it can be used as middle char in the palindrome so
        // add 1 to result and return
        unordered_set<char> charSet;
        int result = 0;
        for (char ch : s) {
            // if set contains the character, means match found and remove the
            // character from set and increase 2 in result
            if (charSet.find(ch) != charSet.end()) {
                charSet.erase(ch);
                result += 2;
            } else {
                // add character in hash set
                charSet.insert(ch);
            }
        }
        // if any character remains, we have at least one unmatched character to
        // make the center of an odd length palindrome.
        return charSet.empty() ? result : result + 1;
    }
};