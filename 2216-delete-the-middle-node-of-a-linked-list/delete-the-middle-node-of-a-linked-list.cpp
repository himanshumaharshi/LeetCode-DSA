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
    int getLength(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while (temp != NULL) {
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode* deleteMiddle(ListNode* head) {
        int len = getLength(head);
        int n = len / 2;
        ListNode* prevNode = head;
        for (int i = 1; i < n; i++) {
            prevNode = prevNode->next;
        }
        if (n == 0) {
            head = NULL;
            return head;
        }
        else {
            ListNode* temp = prevNode->next;
            prevNode->next = prevNode->next->next;
            temp->next = NULL;
            delete temp;
            return head;
        }
    }
};