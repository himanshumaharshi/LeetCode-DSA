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
    int getLength(ListNode*head, ListNode*& ptr)
    {
        int len = 0;
        ListNode *temp = head;
        while(temp != NULL){
            temp = temp->next;
            ptr = temp;
            len++;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        ListNode* temp = head;
        ListNode* ptr = NULL;

        // get length of LL
        int len = 0;
        while(temp != NULL){
            len++;
            ptr = temp;
            temp = temp->next;
        }

        k = k % len;
        cout << k << endl;

        ptr->next = head;
        temp = head;
        k = len - k;
        k--;

        while (k--) {
            temp = temp->next;
        }

        head = temp->next;
        temp->next = NULL;
        return head;
    }
};