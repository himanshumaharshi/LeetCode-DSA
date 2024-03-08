class Node {
    public:
    int val;
    int row;
    int col;

    Node (int val, int row, int col) {
       this->val = val;
       this->row = row;
       this->col = col; 
    }
};

class Compare {
    public:
    bool operator () (Node* a, Node* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<Node *, vector<Node *>, Compare> minHeap;
        int k = nums.size();
        // insert first k elements in the minHeap from each and every list
        for (int i = 0; i < k; i++) {
            int element = nums[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);
            minHeap.push(new Node(element, i, 0));
        }

        int ansStart = mini;
        int ansEnd = maxi;

        while (!minHeap.empty()) {
            Node* top = minHeap.top();
            int topElement = top->val;
            int topRow = top->row;
            int topCol = top->col;
            minHeap.pop();
            // update mini
            mini = topElement;
            // check for answer
            if (maxi - mini < ansEnd - ansStart) {
                ansStart = mini;
                ansEnd = maxi;
            }
            // check for new element in the same list and if present then insert it in minHeap
            if (topCol + 1 < nums[topRow].size()) {
                maxi = max(maxi, nums[topRow][topCol + 1]);
                Node* newNode = new Node(nums[topRow][topCol + 1], topRow, topCol + 1);
                minHeap.push(newNode);
            }
            else {
                // if there is no element is left in the array then break
                break;
            }
        }
        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};