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

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        while (curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        // if head will be null or head->next will be null then return
        if (head == NULL || head->next == NULL) {
            return;
        }

        // find the middle element
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second half of the linked list
        ListNode* newNode = reverseList(slow->next);

        // break the list from the middle
        slow->next = NULL;

        //first half list pointer
        ListNode* curr = head;
        //second half list pointer
        ListNode* dummy = newNode;

        // merge both halfs
        while (head != NULL && dummy != NULL) {
            //pointer to store next element of curr(1st half list)
            ListNode* temp = curr->next;
            //link element of 1st half to that of second half
            curr->next = dummy;
            //pointer to store next element of dummy(2nd half list)
            ListNode* temp2 = dummy->next;
            //link the rest of the first half list
            dummy->next = temp;
            //increment curr and dummy pointer to do the same thing again and again util we reach end of the any one list or both list
            curr = temp;
            dummy = temp2;
        }
    }
};