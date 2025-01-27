// LeetCode: https://leetcode.com/problems/merge-in-between-linked-lists/description/

// My Code:
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
    ListNode* mergeInBetween(ListNode* head, int a, int b, ListNode* list2) {
        ListNode* prev = head;
        ListNode* Next = head;

        if (head == NULL || head->next == NULL) {
            return head;
        }

        while (a != 1 && prev != NULL) {
            prev = prev->next;
            a--;
        }
        while (b != 0 && Next != NULL) {
            Next = Next->next;
            b--;
        }
        prev->next=list2;
        ListNode* temp=list2;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=Next->next;

        return head;
    }
};
