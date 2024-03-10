class Node {
    public:
    char data;
    int count;

    Node (char data, int count) {
        this->data = data;
        this->count = count;
    }
};

class compare {
    public:
    bool operator () (Node a, Node b) {
        return a.count < b.count;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        // create mapping
        int freq[26] = {0};

        // store frequency of characters present in string
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            freq[ch - 'a']++;
        }

        // create maxHeap
        priority_queue<Node, vector<Node>, compare> maxHeap;

        // insert all traced characters with there frequency value into maxHeap
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                Node temp(i + 'a', freq[i]);
                maxHeap.push(temp);
            }
        }

        string ans = "";

        while (maxHeap.size() > 1) {
            // take first and second element from maxHeap and pop them out
            Node first = maxHeap.top();
            maxHeap.pop();
            Node second = maxHeap.top();
            maxHeap.pop();

            // insert both the elements into ans string
            ans += first.data;
            ans += second.data;

            // decrease count of inserted elements
            first.count--;
            second.count--;

            // after insertion if the element is still present then push it back in maxHeap with updated count
            if (first.count != 0) {
                maxHeap.push(first);
            }

            if (second.count != 0) {
                maxHeap.push(second);
            }
        }

        // when only one element is left in maxHeap then insert it seperately
        if (maxHeap.size() == 1) {
            Node temp = maxHeap.top();
            maxHeap.pop();
            if (temp.count == 1) {
                ans += temp.data;
            }
            else {
                return "";
            }
        }

        return ans;
    }
};