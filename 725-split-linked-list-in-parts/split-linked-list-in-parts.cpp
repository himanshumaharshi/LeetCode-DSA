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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, NULL);

        // calculate the size of the list
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }

        int parts = len / k;
        parts++;
        int rem = len % k;

        ListNode* temp1 = head;
        ListNode* temp2 = temp1;
        for (int i = 0; i < k; i++) {
            if (temp1 == NULL) {
                break;
            }
            if (rem) {
                for (int j = 0; j < parts - 1; j++) {
                    temp2 = temp2->next;
                }
                ListNode* newList = temp2->next;
                temp2->next = NULL;
                ans[i] = temp1;
                rem--;
                temp1 = newList;
                temp2 = newList;
            }
            else {
                for (int j = 0; j < parts - 2; j++) {
                    temp2 = temp2->next;
                }
                ListNode* newList = temp2->next;
                temp2->next = NULL;
                ans[i] = temp1;
                temp1 = newList;
                temp2 = newList;
            }
        }
        return ans;
    }
};