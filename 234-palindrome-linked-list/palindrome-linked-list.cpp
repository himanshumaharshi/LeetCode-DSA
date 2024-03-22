/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        ListNode* temp = head;
        while (temp != NULL) {
            nums.push_back(temp->val);
            temp = temp->next;
        }
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            if (nums[s] != nums[e]) {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
};