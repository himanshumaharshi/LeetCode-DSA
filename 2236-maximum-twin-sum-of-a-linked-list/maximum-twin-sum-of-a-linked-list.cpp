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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    int getLength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            len++;
        }
        return len;
    }
    int pairSum(ListNode* head) {
        ListNode *newList1 = head;
        int len = getLength(head);
        // place newList pointer to the n / 2th node
        ListNode* newList2 = head;
        for (int i = 0; i < len / 2; i++) {
            newList2 = newList2->next;
        }
        // reverse n / 2 list
        newList2 = reverse(newList2);

        // calculate the max sum of twin
        int maxSum = 0;
        for (int i = 0; i < len / 2; i++) {
            int sum = newList1->val + newList2->val;
            newList1 = newList1->next;
            newList2 = newList2->next;
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};