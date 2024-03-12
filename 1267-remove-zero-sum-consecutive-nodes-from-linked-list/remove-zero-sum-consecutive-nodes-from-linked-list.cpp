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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // create a new linked list
        ListNode* temp = new ListNode(0);
        // unordered map to store all the sum corresponding to the value of nodes
        unordered_map<int, ListNode*> mp;
        // point temp towards head
        temp->next = head;
        // insert sum of value of nodes with corresponding to node itself
        int sum = 0;
        for(ListNode* i = temp; i != NULL; i = i->next){
            mp[sum += i->val] = i;
        }
        // reset sum and update each node's next pointer to skip zero-sum sublists based on the cumulative sums stored in the map.
        sum = 0;
        for(ListNode* i = temp; i != NULL; i = i->next){
            i->next = mp[sum += i->val]->next;
        }
        return temp->next;
    }
};