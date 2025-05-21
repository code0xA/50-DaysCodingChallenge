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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || k==0) return head;
        int len = 1;
        ListNode* tail = head;
        while(tail->next){
            len++;
            tail = tail->next;
        }
        if (k%len==0) return head;
        k = k%len;
        ListNode* prev = head;
        int cnt = len - k;
        while (cnt!=1){
            cnt--;
            prev=prev->next;
        }
        ListNode* newHead = prev->next;
        prev->next = NULL;
        tail->next = head;
        return newHead;
    }
};