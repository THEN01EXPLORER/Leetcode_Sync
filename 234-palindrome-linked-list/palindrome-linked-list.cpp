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
    ListNode* revlist(ListNode* head) {
        ListNode *prev = nullptr;

        while (head) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if (!head || !head->next) return true;

        ListNode *fast = head, *slow = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *newHead = revlist(slow->next);

        ListNode *c1 = head, *c2 = newHead;

        while (c2) {
            if (c1->val != c2->val) {
                slow->next = revlist(newHead);   // Restore list
                return false;
            }

            c1 = c1->next;
            c2 = c2->next;
        }

        slow->next = revlist(newHead);   // Restore list
        return true;
    }
};