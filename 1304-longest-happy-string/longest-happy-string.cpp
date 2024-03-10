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
    string longestDiverseString(int a, int b, int c) {
        // create maxHeap to insert all the string with there frequency
        priority_queue<Node, vector<Node>, compare> maxHeap;
        if (a > 0) {
            Node temp('a', a);
            maxHeap.push(temp);
        }
        if (b > 0) {
            Node temp('b', b);
            maxHeap.push(temp);
        }
        if (c > 0) {
            Node temp('c', c);
            maxHeap.push(temp);
        }

        // generate string
        string ans = "";
        while (maxHeap.size() > 1) {
            // take first and second element from maxHeap and pop them out
            Node first = maxHeap.top();
            maxHeap.pop();
            Node second = maxHeap.top();
            maxHeap.pop();

            // insert the first element two times as it have maximum frequency
            if (first.count >= 2) {
                ans += first.data;
                ans += first.data;
                first.count -= 2;
            }
            else {
                ans += first.data;
                first.count--;
            }

            // second element will only be inserted two times if its total count is >= 2 and its count is greater than first otherwise it will be inserted one at a time 
            if (second.count >= 2 && second.count >= first.count) {
                ans += second.data;
                ans += second.data;
                second.count -= 2;
            }
            else {
                ans += second.data;
                second.count--;
            }
            
            // after insertion if the element is still present then push it back in maxHeap with updated count
            if (first.count > 0) {
                maxHeap.push(first);
            }
            if (second.count > 0) {
                maxHeap.push(second);
            }
        }

        // when only one element is left in maxHeap then insert it seperately
        if (maxHeap.size() == 1) {
            Node temp = maxHeap.top();
            maxHeap.pop();
            if (temp.count >= 2) {
                ans += temp.data;
                ans += temp.data;
                temp.count -= 2;
            }
            else {
                ans += temp.data;
                temp.count--;
            }
        }
        
        return ans;
    }
};