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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {        
        // place a pointer at tail of list2
        ListNode* tail2 = list2;
        while (tail2->next != NULL)
            tail2 = tail2->next;

        // get starting position -> a
        ListNode* start = list1;
        for (int i = 1; i < a; i++) {
            start = start->next;
        }

        // get ending position -> b
        ListNode* end = list1;
        for (int i = 0; i < b; i++) {
            end = end->next;
        }

        // connect the starting node (a - 1 node) to head of list2
        start->next = list2;

        // connect tail of list 2 with next of end node
        tail2->next = end->next;

        // disconnect end node from list1
        end->next = NULL;

        return list1;
    }
};