class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->childCount = 0;
        this->isTerminal = false;
    }

    void insertWord(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            // it means that the all the character inside word have been inserted and the last character is the root so mark it as terminal
            root->isTerminal = true;
            return;
        }
        char ch = word[0];
        int index = ch - 'a';
        TrieNode *child;
        // if some of the characters from the string are present in starting then if will work
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // not present
            child = new TrieNode(ch);
            root->childCount++;
            root->children[index] = child;
        }
        // recursive call
        insertWord(child, word.substr(1));
    }
};

class Solution {
public:
    // we are solving this question using Tire Data Structure and it is not the optimal approach
    // 1. take all strings in TrieNode as input
    // 2. now we will check single nodes only (longest single node chain will be the common prefix for the provided strings)
    // 3. there are two edge cases which are 1 -> if we have empty then return, 2 -> if any of the string have only one element which means root node is Terminal
    void findLowestCommonPrefix(TrieNode* root, string first, string& ans) {
        if (root->isTerminal) {
            return;
        }
        for (int i = 0; i < first.length(); i++) {
            char ch = first[i];
            if (root->childCount == 1) {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }
            else {
                break;
            }
            if (root->isTerminal) {
                break;
            }
        }
    }

    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        // insert strings
        for (int i = 0; i < strs.size(); i++) {
            root->insertWord(root, strs[i]);
        }
        string ans = "";
        string first = strs[0];
        findLowestCommonPrefix(root, first, ans);
        return ans;
    }
};