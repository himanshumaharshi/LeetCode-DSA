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
    ListNode *reverse(ListNode *&head)
    {
        ListNode *prevNode = NULL;
        ListNode *currNode = head;
        ListNode *nextNode;
        while (currNode != NULL)
        {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }
    
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        // add both linked list
        ListNode *ansHead = NULL;
        ListNode *ansTail = NULL;
        int carry = 0;

        while (head1 != NULL && head2 != NULL)
        {
            // calculate sum
            int sum = carry + head1->val + head2->val;
            // find digit to create node for ans node
            int digit = sum % 10;
            // calculate carry
            carry = sum / 10;
            // create newNode for the digit
            ListNode *newNode = new ListNode(digit);
            // atatch the newNode into the ans LL
            if (ansHead == NULL)
            {
                // inserting iftst Node
                ansHead = newNode;
                ansTail = newNode;
            }
            else
            {
                ansTail->next = newNode;
                ansTail = newNode;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // length of head1 list is greater than length of head2 length
        while (head1 != NULL)
        {
            int sum = carry + head1->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode *newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            head1 = head1->next;
        }
        // length of head2 list is greater than length of head1 length
        while (head2 != NULL)
        {
            int sum = carry + head2->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode *newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            head2 = head2->next;
        }

        // handle carry
        while (carry != 0)
        {
            int sum = carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode *newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
        }

        return ansHead;
    }
};
