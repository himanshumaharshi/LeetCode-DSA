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
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLength(head);
        ListNode* prevNode = head;
        for (int i = 1; i < len - n; i++)
            prevNode = prevNode->next;

        if (head == prevNode && n == len) {
            ListNode* temp = head;
            head = head->next;
            prevNode = head;
            temp->next = NULL;
            delete temp;
        }
        else {
            ListNode* temp = prevNode->next;
            prevNode->next = prevNode->next->next;
            temp->next = NULL;
            delete temp;
        }
        return head;
    }
};