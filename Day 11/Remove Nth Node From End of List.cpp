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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (n){
            fast = fast->next;
            n--;
        }
        if (fast==NULL){
            ListNode* newHead = slow->next;
            delete(slow);
            return newHead;
        }
        while (fast && fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* temp = slow->next;
        slow->next=slow->next->next;
        delete(temp);
        return head;
    }
};